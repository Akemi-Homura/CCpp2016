#include "Mainmenu.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
Mainmenu* Mainmenu::_instance = 0;
void Mainmenu::showInformation(std::map<Student,int>&studentList)
{
	if (isActive)
	{
		std::cout << "----------C/CPP�������A��ɼ���-----------\n"
			<< "1:�鿴�ɼ���\n"
			<< "2:���ѧ��\n"
			<< "3:ɾ��ѧ��\n"
			<< "4:¼��ɼ�\n";
		isActive = false;
	}
	
}

void Mainmenu::getInformation(std::map<Student, int>&)
{
}

Mainmenu * Mainmenu::instance()
{
	if (_instance == 0)
		_instance = new Mainmenu;
	return _instance;
}

Mainmenu::Mainmenu()
{
}


Mainmenu::~Mainmenu()
{
}
