#include "InputScore.h"
#include <iostream>
#include <string>
#include "Student.h"
#include "Mainmenu.h"
InputScore::InputScore()
{
}


void InputScore::showInformation(std::map<Student, int>&studentList)
{
	if (isActive)
	{
		isInputScoreFinish = false;
		for(auto stu:studentList)
			if (stu.first.getScore == -1.0)
			{
				std::cout << "ѧ��:" << stu.first.getStuID
					<< "\n����:" << stu.first.getName
					<< "\n�Ա�:" << stu.first.getSex
					<< "\n��ȷ�Ϻ�����ɼ�,����backȻ�����˵�\n";
				setActive(false);
				return;
			}
		isInputScoreFinish = true;
	}
}

void InputScore::getInformation(std::map<Student, int>&studentList, State *&nowState)
{
	if (isInputScoreFinish)
	{
		std::cout << "����ѧ���ĳɼ�����¼����ϣ���������ص����˵�\n";
		getchar();
		nowState = Mainmenu::instance();
		return;
	}
	if (isActive)return;
	std::string op;
	std::getline(std::cin, op);
	if (op == "back")
	{
		nowState = Mainmenu::instance();
		nowState->setActive(true);
	}
}

InputScore::~InputScore()
{
}
