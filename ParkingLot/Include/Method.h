#ifndef INCLUDE_METHOD_H_
#define INCLUDE_METHOD_H_

#include "Strategy.h"
#include "ParkedNumVisitor.h"
#include "VacantNumVisitor.h"
#include "VacantRatioVisitor.h"

double GetSortNum(ParkedNumVisitor *parkedNumVisitor);
double GetSortNum(VacantNumVisitor *vacantNumVisitor);
double GetSortNum(VacantRatioVisitor *vacantRatioVisitor);

template <typename T>
ParkingLot* Method(vector<ParkingLot*> &parkingLot, T *visitor)
{
	int parkingLotNo = 0;
	double vacantNum = -1;
	vector<ParkingLot*>::iterator it;
	for(it=parkingLot.begin(); it!=parkingLot.end(); it++)
	{
		(*it)->Accept(visitor);
		if(!(visitor->GetisParkingLotFull()))
		{
			if(vacantNum < GetSortNum(visitor))
			{
				vacantNum = GetSortNum(visitor);
				parkingLotNo = it-parkingLot.begin();
			}
		}
	}
	return parkingLot.at(parkingLotNo);
}

#endif /* INCLUDE_METHOD_H_ */
