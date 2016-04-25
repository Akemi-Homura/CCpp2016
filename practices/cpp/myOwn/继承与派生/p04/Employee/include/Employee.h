/**
 * Project Untitled
 */


#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include <string>
#include <iostream>
using namespace std;
class Employee {
public:
    Employee(string no,string name):no(no),name(name) { }
    virtual double getSalary() = 0;

    virtual void showInfor()
    {
        cout<<"work number: "<<no<<endl;
        cout<<"name: "<<name<<endl;
    }
private:
    string no;
    string name;

};

#endif //_EMPLOYEE_H
