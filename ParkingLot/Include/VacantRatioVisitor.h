#ifndef INCLUDE_VACANTRATIOVISITOR_H_
#define INCLUDE_VACANTRATIOVISITOR_H_

#include "Visitor.h"
#include "Manager.h"

class VacantRatioVisitor : public Visitor
{
private:
	double vacantRatioAdmin;
	double vacantRatioParkingLot;
	bool isParkingLotFull;
public:
	VacantRatioVisitor();
	const double GetvacantRatioAdmin(void) const;
	const double GetvacantRatioParkingLot(void) const;
	const bool GetisParkingLotFull(void) const;

	void Visit(Admin *element);
	void Visit(ParkingLot *element);
	void Visit(Manager *element);

};

#endif /* INCLUDE_VACANTRATIOVISITOR_H_ */
