/**
 * Project Untitled
 */


#ifndef _TECHNICIAN_H
#define _TECHNICIAN_H

#include "Employee.h"


class Technician: public Employee {
public: 
    
    double getSalary();
    
    void showInfor();
private: 
    double workHour;
};

#endif //_TECHNICIAN_H