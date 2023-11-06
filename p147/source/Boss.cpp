#include "Boss.h"

Boss::Boss(int id, string name, int deptid)
{
    this->id = id;
    this->name = name;
    this ->deptid = deptid;
}

void Boss::showInfo()
{
    cout<<"职工编号："<<id<<"\t职工姓名:"<<name<<"\t职工岗位:"<<getDeptName()<<"\t岗位职责:管理公司所有事务"<<endl;
}

string Boss::getDeptName()
{
    return string("老板");
}