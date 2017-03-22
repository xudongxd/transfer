#ifndef INCLUDE_VACANTNUM_H_
#define INCLUDE_VACANTNUM_H_

#include "Strategy.h"
#include "Method.h"
#include "VacantNumVisitor.h"

class VacantNum : public Strategy
{
public:
	ParkingLot* Select(vector<ParkingLot*> &parkingLot) const;
};

#endif /* INCLUDE_VACANTNUM_H_ */
