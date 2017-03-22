#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <ctime>
#include <cstdlib>
#include "unistd.h"
#include "Admin.h"
#include "PrintVisitor.h"
using namespace std;


struct ManagerProperty
{
	int adminNum;
	AdminProperty *adminProperty;
};

class Manager: public Element
{
private:
	string managerName;
	vector<Admin*> admin;
public:
	Manager(ManagerProperty &managerProperty);
	const Ticket ParkCar(const Car& car);
	const Car GetCar(const Ticket& ticket);
	const void Print(void);
	void Accept(Visitor *visitor);
	~Manager();
};


#endif /* INCLUDE_MANAGER_H_ */
