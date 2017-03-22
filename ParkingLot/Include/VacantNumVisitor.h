#ifndef INCLUDE_VACANTNUMVISITOR_H_
#define INCLUDE_VACANTNUMVISITOR_H_

#include "Visitor.h"
#include "Manager.h"

class VacantNumVisitor : public Visitor
{
private:
	int vacantNumAdmin;
	int vacantNumParkingLot;
	bool isParkingLotFull;
public:
	VacantNumVisitor();
	const int GetvacantNumAdmin(void) const;
	const int GetvacantNumParkingLot(void) const;
	const bool GetisParkingLotFull(void) const;

	void Visit(Admin *element);
	void Visit(ParkingLot *element);
	void Visit(Manager *element);

};

#endif /* INCLUDE_VACANTNUMVISITOR_H_ */
