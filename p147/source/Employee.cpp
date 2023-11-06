#include "Employee.h"

Employee::Employee(int id, string name, int deptid)
{
    this->id = id;
    this->name = name;
    this ->deptid = deptid;
}

void Employee::showInfo()
{
    cout<<"职工编号："<<id<<"\t职工姓名:"<<name<<"\t职工岗位:"<<getDeptName()<<"\t岗位职责:完成经理交给的任务"<<endl;
}

string Employee::getDeptName()
{
    return string("普通员工");
}