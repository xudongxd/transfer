#include "VacantRatio.h"

ParkingLot* VacantRatio::Select(vector<ParkingLot*> &parkingLot) const
{
	VacantRatioVisitor *visitor = new VacantRatioVisitor();
	ParkingLot* pakring = Method(parkingLot, visitor);
	delete visitor;
	return pakring;
}
