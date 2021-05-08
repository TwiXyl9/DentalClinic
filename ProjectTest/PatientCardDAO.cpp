#include "PatientCardDAO.h"

PatientCardDAO::PatientCardDAO()
{
}

void PatientCardDAO::LoadPatientCards()
{
	xml_document patientCardsDoc;
	patientCardsDoc.load(FILE_PATH.c_str());

	xml_node patientCardsNode = patientCardsDoc.document_element();

	for (auto personCard : patientCardsNode.children("PersonCard"))
	{
		string idString = personCard.child("Id").child_value();
		string nameString = personCard.child("Name").child_value();
		string surnameString = personCard.child("Surname").child_value();
		string phoneString = personCard.child("PhoneNumber").child_value();
		string emailString = personCard.child("Email").child_value();
		string registrationDateString = personCard.child("DateOfRegistration").child_value();	

		PatientCard patientCard;
		patientCard.Id = stoi(idString);
		patientCard.Name = nameString;
		patientCard.Surname = surnameString;
		patientCard.PhoneNumber = phoneString;
		patientCard.Email = emailString;
		patientCard.DateOfRegistration = DateParser::ParseDate(registrationDateString);

		PatientCards.push_back(patientCard);
	}
}

void PatientCardDAO::SavePatientCards()
{
	xml_document patientCardsDoc;

	auto docSave = patientCardsDoc.append_child("PatientCards");

	for (auto patientCard : PatientCards)
	{
		auto cardChild = docSave.append_child("PatientCard");
		auto idChild = cardChild.append_child("Id");
		idChild.append_child(pugi::node_pcdata).set_value(to_string(patientCard.Id).c_str());
		auto nameChild = cardChild.append_child("Name");
		nameChild.append_child(pugi::node_pcdata).set_value(patientCard.Name.c_str());
		auto surnameChild = cardChild.append_child("Surname");
		surnameChild.append_child(pugi::node_pcdata).set_value(patientCard.Surname.c_str());
		auto phoneChild = cardChild.append_child("PhoneNumber");
		phoneChild.append_child(pugi::node_pcdata).set_value(patientCard.PhoneNumber.c_str());
		auto emailChild = cardChild.append_child("Email");
		emailChild.append_child(pugi::node_pcdata).set_value(patientCard.Email.c_str());
		auto dateChild = cardChild.append_child("DateOfRegistration");
		string dateString = to_string(patientCard.DateOfRegistration.tm_mday) + "." + to_string(patientCard.DateOfRegistration.tm_mon + 1) + "." + to_string(patientCard.DateOfRegistration.tm_year);
		emailChild.append_child(pugi::node_pcdata).set_value(dateString.c_str());
	}
	patientCardsDoc.save_file(FILE_PATH.c_str());
}

PatientCard PatientCardDAO::GetCardByNameAndSurname(string name, string surname)
{	
	return PatientCard();
}
