#ifndef INCLUDE_VACANTRATIO_H_
#define INCLUDE_VACANTRATIO_H_

#include "Strategy.h"
#include "Method.h"
#include "VacantRatioVisitor.h"

class VacantRatio : public Strategy
{
public:
	ParkingLot* Select(vector<ParkingLot*> &parkingLot) const;
};

#endif /* INCLUDE_VACANTRATIO_H_ */
