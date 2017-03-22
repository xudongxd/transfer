#ifndef INCLUDE_TICKET_H_
#define INCLUDE_TICKET_H_

#include <cstring>
#include <iostream>
using namespace std;

class Ticket
{
private:
	string adminName;
	string parkingLotName;
	int parkingSpaceNo;
	string licPlaRecOnTicket;
public:
	Ticket();
	Ticket(const string adminName, const string parkingLotName, const int parkingSpaceNo,const string  licPlaRecOnTicket);
	Ticket(const Ticket &ticket);

	const string GetadminName(void) const;
	const string GetparkingLotName(void) const;
	const int GetparkingSpaceNo(void) const;
	const string GetlicPlaRecOnTicket(void) const;

	static Ticket &GetNull(void) ;

	bool  operator ==(const Ticket& ticket);
	bool  operator !=(const Ticket& ticket);
};
#define NULL_TICKET  (Ticket::GetNull())

#endif /* INCLUDE_TICKET_H_ */
