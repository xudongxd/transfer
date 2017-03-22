#ifndef INCLUDE_VISITOR_H_
#define INCLUDE_VISITOR_H_

class Admin;
class ParkingLot;
class Manager;

class Visitor
{
public:
	virtual void Visit(Manager *element) = 0;
	virtual void Visit(Admin *element) = 0;
	virtual void Visit(ParkingLot *element) = 0;
	virtual ~Visitor(){}
};


#endif /* INCLUDE_VISITOR_H_ */
