#pragma once
#include <string>
using namespace std;
class Service {
public:
	Service();
	Service(string name, float price);
	string ServiceTitle;
	float Price;
};