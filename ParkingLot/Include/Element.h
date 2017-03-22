#ifndef INCLUDE_ELEMENT_H_
#define INCLUDE_ELEMENT_H_

#include "Visitor.h"

class Element
{
public:
	virtual const Ticket ParkCar(const Car &car0) = 0;
	virtual const Car GetCar(const Ticket &ticket) = 0;
	virtual void Accept(Visitor *visitor) = 0;
	virtual ~Element(){}
};



#endif /* INCLUDE_ELEMENT_H_ */
