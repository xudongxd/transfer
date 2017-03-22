#ifndef INCLUDE_PRINTVISITOR_H_
#define INCLUDE_PRINTVISITOR_H_

#include "Visitor.h"
#include "Manager.h"
#include "ParkedNumVisitor.h"
#include "VacantNumVisitor.h"
#include "VacantRatioVisitor.h"

class PrintVisitor : public Visitor
{
public:
	PrintVisitor();
	void Visit(ParkingLot *element);
	void Visit(Admin *element);
	void Visit(Manager *element);
};


#endif /* INCLUDE_PRINTVISITOR_H_ */
