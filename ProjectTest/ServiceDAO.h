#pragma once
#include<fstream>
#include<string>
#include<vector>
#include"Service.h"
using namespace std;
class ServiceDAO
{
private:
	string FILE_PATH = "Data/Services.txt";
public:
	ServiceDAO();

	void LoadServices();
	void SaveServices();

	vector<Service> Services;
};
