/**
 * Project Untitled
 */


#include "Salesman.h"
#include <iostream>
using namespace std;
/**
 * Salesman implementation
 */


/**
 * @return double
 */
double Salesman::getSalary() {
    return initialSalary+sale*rate;
}

/**
 * @return void
 */
void Salesman::showInfor() {
    Employee::showInfor();
    cout<<"initial salary: "<<initialSalary<<endl;
    cout<<"sale: "<<sale<<endl;
}
