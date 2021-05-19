#include "TicketDAO.h"
#include "Ticket.h"
#include "DataRepository.h"
TicketDAO::TicketDAO()
{
}

void TicketDAO::LoadTickets()
{
	ifstream file(FILE_PATH);
	string ticketString;
	while (getline(file, ticketString))
	{
		Ticket ticket;
		auto ticketFields = Ticket::GetFields(ticketString);
		ticket.Id = stoi(ticketFields[0]);
		ticket.PatientCardId = stoi(ticketFields[1]);
		ticket.ServiceId = stoi(ticketFields[2]);



		auto dateOfBirthFields = DateAndTime::GetDateAndTimeFields(ticketFields[3]);
		ticket.DateTime.Days = stoi(dateOfBirthFields[0]);
		ticket.DateTime.Months = stoi(dateOfBirthFields[1]);
		ticket.DateTime.Years = stoi(dateOfBirthFields[2]);
		ticket.DateTime.Hours = stoi(dateOfBirthFields[3]);
		ticket.DateTime.Minutes = stoi(dateOfBirthFields[4]);
		ticket.DateTime.Seconds = stoi(dateOfBirthFields[5]);
		ticket.Status = Ticket::StringToStatus(ticketFields[4]);

		Tickets.push_back(ticket);
	}
	file.close();
}

void TicketDAO::SaveTickets()
{
	ofstream file(FILE_PATH);
	for each (Ticket ticket in Tickets)
	{
		file << ticket.Id << ";"
			<< ticket.PatientCardId << ";"
			<< ticket.ServiceId << ";"
			<< ticket.DateTime.DateAndTimeToString() << ";"
			<< ticket.StatusToString() << ";" << endl;
	}
	file.close();
}

int TicketDAO::GetNewId()
{
	int new_id = 0;
	for each (Ticket service in Tickets)
	{
		new_id = service.Id;
	}
	new_id++;
	return new_id;
}


