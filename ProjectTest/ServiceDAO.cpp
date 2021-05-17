#include "ServiceDAO.h"

ServiceDAO::ServiceDAO()
{
}

void ServiceDAO::LoadServices()
{
	ifstream file(FILE_PATH);
	string serviceString;
	while (getline(file, serviceString))
	{
		Service service;
		auto serviceFields = Service::GetFields(serviceString);
		service.Id = stoi(serviceFields[0]);
		service.Title = serviceFields[1];
		service.Price = stof(serviceFields[2]);

		Services.push_back(service);

	}
	file.close();
}

void ServiceDAO::SaveServices()
{
	ofstream file(FILE_PATH);
	for each (Service service in Services)
	{
		file << service.Id << ";"
			<< service.Title << ";"
			<< service.Price << ";" << endl;
	}
	file.close();
}

int ServiceDAO::GetNewId()
{
	int new_id = 0;
	for each (Service service in Services)
	{
		new_id = service.Id;
	}
	new_id++;
	return new_id;
}



