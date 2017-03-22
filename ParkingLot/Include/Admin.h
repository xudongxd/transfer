#ifndef INCLUDE_ADMIN_H_
#define INCLUDE_ADMIN_H_

#include "Strategy.h"
#include "Element.h"

struct AdminProperty
{
	string adminName;
	int ParkingLotNum;
	ParkingLotProperty *parkingLotProperty;
	Strategy *strategy;

};

class Admin : public Element
{
private:
	string adminName;
	vector<ParkingLot*> parkingLot;
	Strategy *strategy;
public:
	Admin(const AdminProperty &adminProperty);
	const string GetadminName(void) const;
	const  int GettotalSpaceNum(void);
	const  int GetemptySpaceNum(void);
	const Ticket ParkCar(const Car& car);
	const Car GetCar(const Ticket& ticket);
	void Accept(Visitor *visitor);
	~Admin();
};


#endif /* INCLUDE_ADMIN_H_ */
