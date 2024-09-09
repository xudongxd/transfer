import requests
from bs4 import BeautifulSoup
from requests.adapters import HTTPAdapter
from urllib3.util.retry import Retry
import csv
import time

# 定义超时重试策略
def requests_retry_session(retries=5, backoff_factor=0.3, status_forcelist=(500, 502, 504)):
    session = requests.Session()
    retry = Retry(
        total=retries,
        read=retries,
        connect=retries,
        backoff_factor=backoff_factor,
        status_forcelist=status_forcelist,
    )
    adapter = HTTPAdapter(max_retries=retry)
    session.mount('http://', adapter)
    session.mount('https://', adapter)
    return session

# 通用的函数，用于根据URL获取BeautifulSoup对象
def fetch_soup_from_url(url):
    try:
        response = requests_retry_session().get(url, timeout=5)
        response.raise_for_status()  # 检查是否成功返回
        soup = BeautifulSoup(response.content, 'html.parser')
        return soup
    except Exception as e:
        print(f"访问 {url} 失败: {e}")
        return None

# 通用函数，用于查找特定的链接并执行进一步处理
def find_link_and_follow(soup, link_class, search_text, next_step_callback):
    if soup:
        # 查找指定 class 且文本包含指定内容的 <a> 标签
        link = soup.find('a', class_=link_class, string=lambda text: search_text in text if text else False)
        if link:
            new_url = link['href']
            print(f"找到的链接: {new_url}")
            
            # 执行下一步操作，通常是访问新的链接并查找更多内容
            return next_step_callback(new_url)
        else:
            print(f"未找到包含 '{search_text}' 的链接")
    return None

# 通用函数，用于查找指定 class 名下的所有链接
def find_all_links(soup, link_class):
    if soup:
        return soup.find_all('a', class_=link_class)
    return []

# 获取class='button'且文本内容包含'school'的链接
def get_final_button_link(new_url):
    soup = fetch_soup_from_url(new_url)
    if soup:
        # 查找 class='button' 且文本包含 'school' 的元素
        return find_link_and_follow(soup, 'button', 'school', lambda x: x)  # 返回找到的链接文本
    return None

# 获取 class='link' 且文本包含 'download' 的链接，并进一步访问其内容
def get_download_link_from_post(post_url):
    soup = fetch_soup_from_url(post_url)
    if soup:
        # 查找 class='link' 且文本包含 'download' 的元素，并进一步执行查找操作
        return find_link_and_follow(soup, 'link', 'download', get_final_button_link)
    return None

# 解析页面并提取标题和链接，并继续获取下载链接和按钮链接
def parse_forum_page(url, post_class_name):
    soup = fetch_soup_from_url(url)
    if soup:
        posts = []
        # 使用通用函数查找所有包含指定 class 的链接
        links = find_all_links(soup, post_class_name)
        for link in links:
            title = link.get_text().strip()
            if '我的' in title:
                href = link['href']
                print(f"抓取的帖子: 标题: {title}, 链接: {href}")

                # 访问每个帖子链接，获取包含 'download' 的链接
                final_button_link = get_download_link_from_post(href)
                
                posts.append({
                    'title': title,
                    'final_button_link': final_button_link
                })
        return posts
    return []

# 主函数，抓取第1到第10页的数据
def scrape_forum(base_url, post_class_name):
    all_posts = []
    
    for page in range(1, 11):
        url = f"{base_url}?page={page}"
        print(f"正在抓取: {url}")
        
        posts = parse_forum_page(url, post_class_name)
        all_posts.extend(posts)

        # 为了避免请求过快，加入延时
        time.sleep(2)
    
    return all_posts

# 将数据保存到CSV文件
def save_to_csv(posts, filename='forum_posts.csv'):
    # 只保存 'title' 和 'final_button_link'
    fieldnames = ['title', 'final_button_link']
    
    try:
        # 打开文件并写入数据
        with open(filename, mode='w', newline='', encoding='utf-8') as file:
            writer = csv.DictWriter(file, fieldnames=fieldnames)
            writer.writeheader()  # 写入标题行
            writer.writerows(posts)  # 写入数据行
        print(f"数据已保存到 {filename}")
    except Exception as e:
        print(f"保存到CSV文件时出错: {e}")

# 示例运行，假设论坛URL为 'http://example.com/forum'
if __name__ == '__main__':
    base_url = 'http://example.com/forum'  # 替换为实际的论坛URL
    post_class_name = 'post-title'  # 传入包含帖子标题的类名
    
    result = scrape_forum(base_url, post_class_name)

    # 只打印 'title' 和 'final_button_link'
    for post in result:
        print(f"标题: {post['title']}, 最终按钮链接: {post['final_button_link']}")
    
    # 保存结果到CSV文件
    save_to_csv(result, 'forum_posts.csv')
