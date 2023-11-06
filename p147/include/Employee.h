#pragma once
#include <iostream>
using namespace std;
#include "Staff.h"

class Employee: public Staff
{
public:
    Employee(int id, string name, int deptid);

    void showInfo();

    string getDeptName();
};