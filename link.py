import requests
from bs4 import BeautifulSoup
from requests.adapters import HTTPAdapter
from urllib3.util.retry import Retry
import csv
import time
from urllib.parse import urljoin  # 新增，用于拼接URL

# 全局变量，方便修改
BASE_URL = 'http://example.com/forum'  # 论坛的基础 URL
ATTR_POST_TITLE = {'class': 'post-title'}  # 帖子标题的属性
ATTR_LINK = {'class': 'link'}  # 下载链接的属性
ATTR_BUTTON = {'class': 'button'}  # 按钮链接的属性

TEXT_POST_TITLE = '我的'  # 帖子标题中包含的关键字
TEXT_LINK = 'download'  # 链接文本中包含的关键字
TEXT_BUTTON = 'school'  # 最终按钮文本中包含的关键字

LOG_FILE = 'scraping_log.txt'  # 日志文件


# 定义记录日志的函数
def log_message(message):
    """将信息写入日志文件"""
    with open(LOG_FILE, 'a', encoding='utf-8') as f:
        f.write(f"{message}\n")


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
        log_message(f"访问 {url} 失败: {e}")
        return None


# 通用函数，用于查找特定属性的链接并执行进一步处理
def find_link_and_follow(soup, attributes_map, search_text, next_step_callback):
    if soup:
        # 查找符合 attributes_map 的 <a> 标签，并且其文本包含 search_text
        link = soup.find('a', attrs=attributes_map, string=lambda text: search_text in text if text else False)
        if link:
            new_url = link['href']
            log_message(f"找到的链接: {new_url}")

            # 执行下一步操作，通常是访问新的链接并查找更多内容
            return next_step_callback(new_url)
        else:
            log_message(f"未找到包含 '{search_text}' 的链接")
    return None


# 通用函数，用于查找指定属性的所有链接
def find_all_links(soup, attributes_map):
    if soup:
        return soup.find_all('a', attrs=attributes_map)
    return []


# 获取符合 ATTR_BUTTON 的链接且文本内容包含 TEXT_BUTTON 的链接
def get_final_button_link(new_url):
    soup = fetch_soup_from_url(new_url)
    if soup:
        # 查找符合 ATTR_BUTTON 的 <a> 标签，文本包含 TEXT_BUTTON
        return find_link_and_follow(soup, ATTR_BUTTON, TEXT_BUTTON, lambda x: x)  # 返回找到的链接文本
    return None


# 获取符合 ATTR_LINK 的链接且文本包含 TEXT_LINK 的链接，并进一步访问其内容
def get_download_link_from_post(post_url):
    soup = fetch_soup_from_url(post_url)
    if soup:
        # 查找符合 ATTR_LINK 的 <a> 标签，文本包含 TEXT_LINK
        return find_link_and_follow(soup, ATTR_LINK, TEXT_LINK, get_final_button_link)
    return None


# 解析页面并提取标题和链接，并继续获取下载链接和按钮链接
def parse_forum_page(url, post_attributes):
    soup = fetch_soup_from_url(url)
    if soup:
        posts = []
        # 使用通用函数查找所有符合 post_attributes 的链接
        links = find_all_links(soup, post_attributes)
        for link in links:
            title = link.get_text().strip()
            if TEXT_POST_TITLE in title:
                href = link['href']
                # 将帖子的 href 与 BASE_URL 拼接为完整链接
                full_url = urljoin(BASE_URL, href)
                log_message(f"抓取的帖子: 标题: {title}, 链接: {full_url}")

                # 访问每个帖子链接，获取包含 TEXT_LINK 的链接
                final_button_link = get_download_link_from_post(full_url)

                # 只保存 final_button_link 不为 None 的记录
                if final_button_link:
                    posts.append({
                        'title': title,
                        'final_button_link': final_button_link
                    })
        return posts
    return []


# 主函数，抓取第1到第10页的数据
def scrape_forum():
    all_posts = []

    for page in range(1, 11):
        url = f"{BASE_URL}?page={page}"
        log_message(f"正在抓取: {url}")

        posts = parse_forum_page(url, ATTR_POST_TITLE)
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
        log_message(f"数据已保存到 {filename}")
    except Exception as e:
        log_message(f"保存到CSV文件时出错: {e}")


# 示例运行
if __name__ == '__main__':
    result = scrape_forum()

    # 将 'title' 和 'final_button_link' 写入日志
    for post in result:
        log_message(f"标题: {post['title']}, 最终按钮链接: {post['final_button_link']}")

    # 保存结果到CSV文件
    save_to_csv(result, 'forum_posts.csv')
