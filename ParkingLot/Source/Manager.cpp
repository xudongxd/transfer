#include "Manager.h"

Manager::Manager(ManagerProperty &managerProperty)
{
	for(int i=0;i<managerProperty.adminNum;i++)
	{
		admin.push_back(new Admin(*(managerProperty.adminProperty+i)));
	}
}

const Ticket Manager::ParkCar(const Car& car)
{
	Ticket ticketGivenToCustomer;
	int emptyAdminNum = admin.size();
	do{
		srand((int)time(0));
		int adminNo = rand()%emptyAdminNum;
		Ticket temp = admin.at(adminNo)->ParkCar(car);
		if(temp != NULL_TICKET)
		{
			sleep(1);
			ticketGivenToCustomer = temp;
			break;
		}
		else
		{
			swap(admin.at(adminNo) ,admin.at(emptyAdminNum-1));
			emptyAdminNum--;
		}
	}while(emptyAdminNum>0);
	if(ticketGivenToCustomer == NULL_TICKET)
		cout<<"停车位已满！"<<endl;
	return ticketGivenToCustomer;

}
const Car Manager::GetCar(const Ticket& ticket)
{
	Car carGivenToCustomer;
	vector<Admin*>::iterator it;
	for(it=admin.begin(); it!=admin.end(); it++)
	{
		if((*it)->GetadminName() == ticket.GetadminName())
		{
			Car temp=(*it)->GetCar(ticket);
			carGivenToCustomer = temp;
			break;
		}
	}
	if(carGivenToCustomer == NULL_CAR)
		cout<<"票据无效！"<<endl;
	return carGivenToCustomer;
}

const void Manager::Print(void)
{
	vector <Admin*>::iterator it;
	for(it=admin.begin(); it!=admin.end(); it++)
	{
		PrintVisitor *v = new PrintVisitor();
		(*it)->Accept(v);
		delete v;
	}
}

void Manager::Accept(Visitor *visitor)
{
	visitor->Visit(this);
}
Manager::~Manager()
{
	vector<Admin*>::iterator it;
	for(it=admin.begin(); it!=admin.end(); it++)
		delete (*it);
};
