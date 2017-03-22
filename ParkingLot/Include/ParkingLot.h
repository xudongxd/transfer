#ifndef INCLUDE_PARKINGLOT_H_
#define INCLUDE_PARKINGLOT_H_

#include "Car.h"
#include "Ticket.h"
#include "Element.h"
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

struct ParkingLotProperty
{
	string parkingLotName;
	int totalSpaceNum;
};

class ParkingLot : public Element
{
private:
	string parkingLotName;
	vector<Car*> parkingSpace;
public:
	ParkingLot(const ParkingLotProperty &parkingLotProperty);
	const string GetparkingLotName(void) const;
	const  int GettotalSpaceNum(void) const;
	const  int GetemptySpaceNum(void);
	const Ticket ParkCar(const Car &car);
	const Car GetCar(const Ticket &ticket);
	void Accept(Visitor *visitor);
	~ParkingLot();
};

#endif /* INCLUDE_PARKINGLOT_H_ */
