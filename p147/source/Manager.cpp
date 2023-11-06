#include "Manager.h"

Manager::Manager(int id, string name, int deptid)
{
    this->id = id;
    this->name = name;
    this ->deptid = deptid;
}

void Manager::showInfo()
{
    cout<<"职工编号："<<id<<"\t职工姓名:"<<name<<"\t职工岗位:"<<getDeptName()<<"\t岗位职责:完成老板交给的任务"<<endl;
}

string Manager::getDeptName()
{
    return string("经理");
}