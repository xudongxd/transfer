#include "VacantNumVisitor.h"

VacantNumVisitor::VacantNumVisitor()
{
	this->isParkingLotFull =false;
	this->vacantNumAdmin = 0;
	this->vacantNumParkingLot = 0;
}

const int VacantNumVisitor::GetvacantNumAdmin(void) const
{
	return this->vacantNumAdmin;
}
const int VacantNumVisitor::GetvacantNumParkingLot(void) const
{
	return this->vacantNumParkingLot;
}
const bool VacantNumVisitor::GetisParkingLotFull(void) const
{
	if(isParkingLotFull)
		return true;
	else
		return false;
}

void VacantNumVisitor::Visit(Admin *element)
{
	this->vacantNumAdmin = element->GetemptySpaceNum();
}
void VacantNumVisitor::Visit(ParkingLot *element)
{
	this->vacantNumParkingLot = element->GetemptySpaceNum();
	if(element->GetemptySpaceNum() == 0)
		isParkingLotFull = true;
	else
		isParkingLotFull =false;
}

void VacantNumVisitor::Visit(Manager *element)
{

}
