#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Identity
{
    public:
        string name;    //姓名
        string password;    //密码

        virtual void openMenu() = 0;    //操作菜单

};