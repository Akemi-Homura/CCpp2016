/**
 * Project Untitled
 */


#ifndef _SALESMAN_H
#define _SALESMAN_H

#include "Employee.h"

double Salesman::rate=0.04;
class Salesman: public Employee {
public:
    Salesman(string no,string name,double sale,double initialSalary):Employee(no,name)
    {
        this->sale=sale;
        this->initialSalary=initialSalary;
    }
    double getSalary();

    void showInfor();
private:
    double sale;
    double initialSalary;
    static double rate;
};

#endif //_SALESMAN_H
