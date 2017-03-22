#include "ParkedNumVisitor.h"

ParkedNumVisitor::ParkedNumVisitor()
{
	this->isParkingLotFull =false;
	this->parkedNumAdmin = 0;
	this->parkedNumParkingLot = 0;
}

const int ParkedNumVisitor::GetparkedNumAdmin(void) const
{
	return this->parkedNumAdmin;
}
const int ParkedNumVisitor::GetparkedNumParkingLot(void) const
{
	return this->parkedNumParkingLot;
}
const bool ParkedNumVisitor::GetisParkingLotFull(void) const
{
	if(isParkingLotFull)
		return true;
	else
		return false;
}

void ParkedNumVisitor::Visit(Admin *element)
{
	this->parkedNumAdmin = element->GettotalSpaceNum() - element->GetemptySpaceNum();
}
void ParkedNumVisitor::Visit(ParkingLot *element)
{
	this->parkedNumParkingLot = element->GettotalSpaceNum() - element->GetemptySpaceNum();
	if(element->GetemptySpaceNum() == 0)
		isParkingLotFull = true;
	else
		isParkingLotFull =false;
}

void ParkedNumVisitor::Visit(Manager *element)
{
}
