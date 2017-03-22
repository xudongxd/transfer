#include <PrintVisitor.h>

PrintVisitor::PrintVisitor()
{

}

void PrintVisitor::Visit(ParkingLot *element)
{

}

void PrintVisitor::Visit(Admin *element)
{
	ParkedNumVisitor *parkedNumVisitor = new ParkedNumVisitor();
	VacantNumVisitor *vacantNumVisitor = new VacantNumVisitor();
	VacantRatioVisitor *vacantRatioVisitor = new VacantRatioVisitor();
	element->Accept(parkedNumVisitor);
	element->Accept(vacantNumVisitor);
	element->Accept(vacantRatioVisitor);
	cout<<element->GetadminName()<<":"<<endl
		   <<"	"<<parkedNumVisitor->GetparkedNumAdmin()
		   <<"	"<<vacantNumVisitor->GetvacantNumAdmin()
		   <<"	"<<vacantRatioVisitor->GetvacantRatioAdmin()
		   <<endl;
	delete parkedNumVisitor;
	delete vacantNumVisitor;
	delete vacantRatioVisitor;
}

void PrintVisitor::Visit(Manager *element)
{

}
