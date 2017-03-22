#include "ParkingLot.h"

ParkingLot::ParkingLot(const ParkingLotProperty &parkingLotProperty)
{
	this->parkingLotName = parkingLotProperty.parkingLotName;
	for(int i=0;i<parkingLotProperty.totalSpaceNum;i++)
		parkingSpace.push_back(new Car);
}

const string ParkingLot::GetparkingLotName(void) const
{
	return this->parkingLotName;
}

const  int ParkingLot::GettotalSpaceNum(void) const
{
	return parkingSpace.size();
}

const int ParkingLot::GetemptySpaceNum(void)
{
	int emptySpaceNum = 0;
	vector<Car*>::iterator it;
	for(it=parkingSpace.begin(); it!=parkingSpace.end(); it++)
	{
		if(**it==NULL_CAR)
		{
			emptySpaceNum++;
		}
	}
	return emptySpaceNum;
}
const Ticket ParkingLot::ParkCar(const Car &car)
{
	Ticket ticketGivenToCustomer;
	string licPlaRecOnTicket = "\0";
	vector<Car*>::iterator it;
	for(it = parkingSpace.begin(); it != parkingSpace.end(); it++)
	{
		if(**it == NULL_CAR)
		{
			**it = car;
			Ticket temp("\0", parkingLotName, it-parkingSpace.begin()+1, car.GetlicencePlate());
			ticketGivenToCustomer = temp;
			break;
		}
	}
	return ticketGivenToCustomer;
}

const Car ParkingLot::GetCar(const Ticket &ticket)
{
	Car carGivenToCustomer;
	int parkingSpaceNum = ticket.GetparkingSpaceNo();
	if(ticket.GetlicPlaRecOnTicket() == parkingSpace.at(parkingSpaceNum-1)->GetlicencePlate())
	{
		carGivenToCustomer = *parkingSpace.at(parkingSpaceNum-1);
		*parkingSpace.at(parkingSpaceNum-1) = NULL_CAR;

		cout<<"车牌号为"<<ticket.GetlicPlaRecOnTicket()<<"的车主，您的车已经取出"<<endl;
	}
	if(carGivenToCustomer ==NULL_CAR)
		cout<<"票据无效！"<<endl;
	return carGivenToCustomer;
}

void ParkingLot::Accept(Visitor *visitor)
{
	visitor->Visit(this);
}

ParkingLot::~ParkingLot()
{
	vector<Car*>::iterator it;
	for(it=parkingSpace.begin(); it!=parkingSpace.end(); it++)
		delete (*it);
}
