/**
 * Project Untitled
 */


#ifndef _MANAGER_H
#define _MANAGER_H

#include "Employee.h"


class Manager: public Employee {
public: 
    
    double getSalary();
    
    void showInfor();
private: 
    double initialSalary;
};

#endif //_MANAGER_H