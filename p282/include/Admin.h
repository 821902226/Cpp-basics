#pragma once
#include <iostream>
#include "Identity.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Computer.h"
#include <vector>
#include <algorithm>

using namespace std;

class Admin:public Identity
{
    public:
        vector<Student> vStu;   //学生容器
        vector<Teacher> vTea;   //老师容器
        vector<Computer> vCom;   //机房容器

        Admin();

        Admin(string name, string password);

        //打开操作菜单
        virtual void openMenu();

        //添加账号
        void addAccount();

        //查看账号
        void showAccount();

        //查看机房信息
        void showComputer();

        //清空预约记录
        void clearRecord();

        //初始化容器 保存老师和学生的信息
        void initVector();

        //检测重复id
        bool checkRepeat(int id, int type);

};
