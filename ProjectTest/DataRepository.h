#pragma once
#include "PatientCardDAO.h"
#include "ServiceDAO.h"
#include "TicketDAO.h"

class DataRepository {
public:
	DataRepository();
	static PatientCardDAO patientCardDAO;
	static ServiceDAO serviceDAO;
	static TicketDAO ticketDAO;
};
