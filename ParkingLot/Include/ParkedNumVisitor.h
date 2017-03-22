#ifndef INCLUDE_PARKEDNUMVISITOR_H_
#define INCLUDE_PARKEDNUMVISITOR_H_

#include "Visitor.h"
#include "Manager.h"

class ParkedNumVisitor : public Visitor
{
private:
	int parkedNumAdmin;
	int parkedNumParkingLot;
	bool isParkingLotFull;
public:
	ParkedNumVisitor();
	const int GetparkedNumAdmin(void) const;
	const int GetparkedNumParkingLot(void) const;
	const bool GetisParkingLotFull(void) const;

	void Visit(Admin *element);
	void Visit(ParkingLot *element);
	void Visit(Manager *element);
};


#endif /* INCLUDE_PARKEDNUMVISITOR_H_ */
