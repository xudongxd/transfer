#include "Car.h"

Car::Car()
{
	this->licencePlate = "\0";
}
Car::Car(const string licencePlate)
{
	this->licencePlate = licencePlate;
}
Car::Car(const Car & car)
{
	this->licencePlate = car.licencePlate;
}
const string Car::GetlicencePlate(void) const
{
	return this->licencePlate;
}

Car& Car::GetNull(void)
{
	static Car null;
	return null;
}

const bool Car::operator ==(const Car & car) const
{
	if(this->licencePlate == car.licencePlate)
		return true;
	else
		return false;
}
const bool Car::operator !=(const Car & car) const
{
	if(this->licencePlate != car.licencePlate)
		return true;
	else
		return false;
}
