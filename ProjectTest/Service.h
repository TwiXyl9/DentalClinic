#pragma once
#include <string>
#include <vector>
using namespace std;
class Service 
{
public:
	Service();

	static vector<string>GetFields(string service);

	int Id;
	string Title;
	float Price;
};