#include "DataRepository.h"

DataRepository::DataRepository()
{

}

PatientCardDAO DataRepository::patientCardDAO = PatientCardDAO();
ServiceDAO DataRepository::serviceDAO = ServiceDAO();
TicketDAO DataRepository::ticketDAO = TicketDAO();