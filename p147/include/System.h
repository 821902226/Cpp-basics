#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Staff.h"
#include "Boss.h"
#include "Manager.h"
#include "Employee.h"
using namespace std;

#define FILE "Staff.txt"

class System
{
public:
    int staffNum;
    Staff ** staffSet;
    bool fileIsEmpty;

    System();

    //显示菜单
    void showMenu();

    //添加员工
    void addStaff();

    //保存文件
    void saveFile();

    //统计人数
    int getStaffNum();

    //初始化职工
    void initStaff();

    //显示职工信息
    void showStaffInfo();

    //判断职工是否存在（根据id查找,返回其在数组中的位置）
    int isExist(int id);

    //删除职工
    void deleteStaff();

    //修改职工信息
    void modifyStaff();

    //查找职工信息
    void searchStaff();

    //按照职工编号进行排序
    void sortStaff();

    //清空文件 
    void cleanFile();

    //退出系统
    void exitSystem();

    ~System();
};