#pragma once
#include <iostream>
using namespace std;
#include "Staff.h"

class Manager: public Staff
{
public:
    Manager(int id, string name, int deptid);

    void showInfo();

    string getDeptName();
};