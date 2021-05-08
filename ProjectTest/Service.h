#pragma once
#include <string>
using namespace std;
class Service 
{
public:
	Service();

	static string* GetFields(string service);

	int Id;
	string Title;
	float Price;
};