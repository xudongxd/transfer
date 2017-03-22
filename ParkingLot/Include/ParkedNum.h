#ifndef INCLUDE_PARKEDNUM_H_
#define INCLUDE_PARKEDNUM_H_

#include "Strategy.h"
#include "Method.h"
#include "ParkedNumVisitor.h"

class ParkedNum : public Strategy
{
public:
	ParkingLot* Select(vector<ParkingLot*> &parkingLot) const;
};


#endif /* INCLUDE_PARKEDNUM_H_ */
