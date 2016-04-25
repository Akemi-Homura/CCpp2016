/**
 * Project Untitled
 */


#ifndef _SALESMANAGER_H
#define _SALESMANAGER_H

#include "Employee.h"


class Salesmanager: public Employee {
public: 
    
    double getSalary();
    
    void showInfor();
private: 
    double sale;
    double initialSalary;
};

#endif //_SALESMANAGER_H