#include "Mainmenu.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
/*
#include "ViewStudentList"
#include "AddStudent"
#include "DeleteStudent"
#include "InputScore"
*/
Mainmenu* Mainmenu::_instance = 0;
void Mainmenu::showInformation(std::map<Student,int>&studentList)
{
	if (isActive)
	{
		std::cout << "----------C/CPP�ɼ�������-----------\n"
			<< "1:�鿴�ɼ���\n"
			<< "2:���ѧ��\n"
			<< "3:ɾ��ѧ��\n"
			<< "4:¼��ɼ�\n";
			<< "5:�˳�\n"
		isActive = false;
	}
	
}

void Mainmenu::getInformation(std::map<Student, int>&)
{
	if (isActive)return;
	int op
}

Mainmenu * Mainmenu::instance()
{
	if (_instance == 0)
		_instance = new Mainmenu;
	return _instance;
}

Mainmenu::Mainmenu()
{
	alternativeStates.push_back();

}


Mainmenu::~Mainmenu()
{
}
