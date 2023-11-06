#pragma once
#include <iostream>
#include <Staff.h>
using namespace std;

class Boss: public Staff
{
public:
    Boss(int id, string name, int deptid);

    void showInfo();

    string getDeptName();
};