 #include "ParkedNum.h"

ParkingLot* ParkedNum::Select(vector<ParkingLot*> &parkingLot) const
{
	ParkedNumVisitor *visitor = new ParkedNumVisitor();
	ParkingLot* pakring = Method(parkingLot, visitor);
	delete visitor;
	return pakring;
}
