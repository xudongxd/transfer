#ifndef INCLUDE_STRATEGY_H_
#define INCLUDE_STRATEGY_H_

#include "ParkingLot.h"

class Strategy
{
public:
	virtual ParkingLot* Select(vector<ParkingLot*> &parkingLot) const = 0;
	virtual ~Strategy(){}
};

#endif /* INCLUDE_STRATEGY_H_ */
