#include "VacantRatioVisitor.h"

VacantRatioVisitor::VacantRatioVisitor()
{
	this->isParkingLotFull =false;
	this->vacantRatioAdmin = 0;
	this->vacantRatioParkingLot = 0;
}

const double VacantRatioVisitor::GetvacantRatioAdmin(void) const
{
	return this->vacantRatioAdmin;
}
const double VacantRatioVisitor::GetvacantRatioParkingLot(void) const
{
	return this->vacantRatioParkingLot;
}
const bool VacantRatioVisitor::GetisParkingLotFull(void) const
{
	if(isParkingLotFull)
		return true;
	else
		return false;
}

void VacantRatioVisitor::Visit(Admin *element)
{
	this->vacantRatioAdmin = double(element->GetemptySpaceNum())/element->GettotalSpaceNum();
}
void VacantRatioVisitor::Visit(ParkingLot *element)
{
	this->vacantRatioParkingLot = double(element->GetemptySpaceNum())/element->GettotalSpaceNum();
	if(element->GetemptySpaceNum() == 0)
		isParkingLotFull = true;
	else
		isParkingLotFull =false;
}

void VacantRatioVisitor::Visit(Manager *element)
{

}
