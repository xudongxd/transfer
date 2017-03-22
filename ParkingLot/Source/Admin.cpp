#include "Admin.h"

Admin::Admin(const AdminProperty &adminProperty)
{
	this->adminName = adminProperty.adminName;
	this->strategy = adminProperty.strategy;
	for(int i=0;i<adminProperty.ParkingLotNum;i++)
		parkingLot.push_back( new ParkingLot(*(adminProperty.parkingLotProperty+i)));
}

const string Admin::GetadminName(void) const
{
	return this->adminName;
}

const  int Admin::GettotalSpaceNum(void)
{
	int totalSpaceNum = 0;
	vector<ParkingLot*>::iterator it;
	for(it = parkingLot.begin(); it != parkingLot.end(); it++)
	{
		totalSpaceNum += (*it)->GettotalSpaceNum();
	}
	return totalSpaceNum;
}
const  int Admin::GetemptySpaceNum(void)
{
	int emptySpaceNum = 0;
	vector<ParkingLot*>::iterator it;
	for(it = parkingLot.begin(); it != parkingLot.end(); it++)
	{
		emptySpaceNum += (*it)->GetemptySpaceNum();
	}
	return emptySpaceNum;
}

const Ticket Admin::ParkCar(const Car& car)
{
		Ticket ticketGivenToCustomer;
		Ticket temp = strategy->Select(parkingLot)->ParkCar(car);
		if(temp !=NULL_TICKET)
		{
			cout<<adminName
					<<":"
					<<"车牌号为："	<<temp.GetlicPlaRecOnTicket()
					<<"的停车位为："
					<<temp.GetparkingLotName()
					<<"--"
					<<temp.GetparkingSpaceNo()
					<<endl;

			Ticket ticket(adminName, temp.GetparkingLotName(), temp.GetparkingSpaceNo(),temp.GetlicPlaRecOnTicket());
			ticketGivenToCustomer = ticket;
			return ticketGivenToCustomer;
		}
		return ticketGivenToCustomer;
}

const Car Admin::GetCar(const Ticket& ticket)
{
	Car carGivenToCustomer;
	vector<ParkingLot*>::iterator it;
	for(it = parkingLot.begin(); it != parkingLot.end(); it++)
	{
		if((*it)->GetparkingLotName() == ticket.GetparkingLotName())
		{
			Car temp = (*it)->GetCar(ticket);
			carGivenToCustomer = temp;
		}
	}
	if(carGivenToCustomer == NULL_CAR)
		cout<<"票据无效！"<<endl;
	return carGivenToCustomer;
}

void Admin::Accept(Visitor *visitor)
{
	visitor->Visit(this);
}

Admin::~Admin()
{
	vector<ParkingLot*>::iterator it;
	for(it = parkingLot.begin(); it != parkingLot.end(); it++)
		delete (*it);
}
