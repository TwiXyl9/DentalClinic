#pragma once
#include "Service.h"
#include <vector>
#include <pugixml.hpp>
#include<string>
using namespace std;
class ServiceDAO {
public:
	//путь к файлу, где хранятся информация о данных пациента
	const string FILE_PATH = "Data/Services.xml";

	//конструторы
	ServiceDAO();

	//методы
	void LoadServices();
	void SaveServices();

	//методы

	//все услуги клиники
	vector<Service> Services;

};
