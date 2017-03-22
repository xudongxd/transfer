#include "VacantNum.h"

ParkingLot* VacantNum::Select(vector<ParkingLot*> &parkingLot) const
{
	VacantNumVisitor *visitor = new VacantNumVisitor();
	ParkingLot* pakring = Method(parkingLot, visitor);
	delete visitor;
	return pakring;
}
