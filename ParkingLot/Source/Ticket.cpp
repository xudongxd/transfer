#include "Ticket.h"

Ticket::Ticket()
{
	this->adminName = "\0";
	this->parkingLotName = "\0";
	this->parkingSpaceNo = 0;
	this->licPlaRecOnTicket = "\0";
}
Ticket::Ticket(const string adminName, const string parkingLotName,
		const int parkingSpaceNo,const string  licPlaRecOnTicket)
{
	this->adminName = adminName;
	this->parkingLotName = parkingLotName;
	this->parkingSpaceNo = parkingSpaceNo;
	this->licPlaRecOnTicket = licPlaRecOnTicket;
}
Ticket::Ticket(const Ticket &ticket)
{
	this->adminName = ticket.adminName;
	this->parkingLotName = ticket.parkingLotName;
	this->parkingSpaceNo = ticket.parkingSpaceNo;
	this->licPlaRecOnTicket = ticket.licPlaRecOnTicket;
}

const string Ticket::GetadminName(void) const
{
	return this->adminName;
}

const string Ticket::GetparkingLotName(void) const
{
	return this->parkingLotName;
}
const int Ticket::GetparkingSpaceNo(void) const
{
	return this->parkingSpaceNo;
}
const string Ticket::GetlicPlaRecOnTicket(void) const
{
	return this->licPlaRecOnTicket;
}

Ticket& Ticket::GetNull(void)
{
	static Ticket null;
	return null;
}

bool  Ticket::operator ==(const Ticket& ticket)
{
	if(this->adminName == ticket.adminName&&
		this->parkingLotName == ticket.parkingLotName &&
		this->parkingSpaceNo == ticket.parkingSpaceNo &&
		this->licPlaRecOnTicket == ticket.licPlaRecOnTicket)
		return true;
	else
		return false;
}
bool Ticket::operator !=(const Ticket& ticket)
{
	if(this->adminName != ticket.adminName||
		this->parkingLotName != ticket.parkingLotName ||
		this->parkingSpaceNo != ticket.parkingSpaceNo ||
		this->licPlaRecOnTicket != ticket.licPlaRecOnTicket)
		return true;
	else
		return false;
}
