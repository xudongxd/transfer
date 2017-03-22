#include "Method.h"

double GetSortNum(ParkedNumVisitor *parkedNumVisitor)
{
	return parkedNumVisitor->GetparkedNumParkingLot();
}
double GetSortNum(VacantNumVisitor *vacantNumVisitor)
{
	return vacantNumVisitor->GetvacantNumParkingLot();
}
double GetSortNum(VacantRatioVisitor *vacantRatioVisitor)
{
	return vacantRatioVisitor->GetvacantRatioParkingLot();
}
