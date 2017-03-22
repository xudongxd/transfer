#ifndef INCLUDE_CAR_H_
#define INCLUDE_CAR_H_

#include <string>
using namespace std;
class Car
{
private:
	string licencePlate;
public:
	Car();
	Car(const string licencePlate);
	Car(const Car & car);

	const string GetlicencePlate(void) const;
	static Car &GetNull(void) ;
	const bool operator ==(const Car & car) const;
	const bool operator !=(const Car & car) const;
};

#define NULL_CAR  (Car::GetNull())

#endif /* INCLUDE_CAR_H_ */
