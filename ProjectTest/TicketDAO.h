#pragma once
#include<vector>
#include<fstream>
#include<string>
#include"Ticket.h"
using namespace std;
class TicketDAO
{
private:
	string FILE_PATH = "Data/Tickets.txt";
public:
	TicketDAO();

	vector<Ticket> Tickets;

	void LoadTickets();
	void SaveTickets();

};