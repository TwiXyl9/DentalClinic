#pragma once
#include "Service.h"
#include <vector>
#include <pugixml.hpp>
#include<string>
using namespace std;
class ServiceDAO {
public:
	//���� � �����, ��� �������� ���������� � ������ ��������
	const string FILE_PATH = "Data/Services.xml";

	//�����������
	ServiceDAO();

	//������
	void LoadServices();
	void SaveServices();

	//������

	//��� ������ �������
	vector<Service> Services;

};
