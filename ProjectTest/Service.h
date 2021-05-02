#pragma once
#include <string>
using namespace std;
class Service {
public:
	//конструкторы
	Service();
	Service(string name, float price);
	//конструкторы

	//id услуги
	int Id;
	//название услуги
	string ServiceTitle;
	//ориентировочная стоимость
	float Price;
};