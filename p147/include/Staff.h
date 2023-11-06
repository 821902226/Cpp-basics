#pragma once
#include <iostream>
#include <string>
using namespace std;


//职工抽象类
class Staff
{
public:
    int id;         //职工编号
    string name;    //职工姓名
    int deptid;     //部门编号

    virtual void showInfo() = 0;    //显示个人信息

    virtual string getDeptName() = 0;     //获取岗位名称
};