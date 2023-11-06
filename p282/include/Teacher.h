#pragma once
#include <iostream>
#include <vector>
#include "Order.h"
#include "Identity.h"

using namespace std;

class Teacher:public Identity
{
    public:
        int t_id;

        Teacher();

        Teacher(int id, string name, string password);
        
        //打开操作菜单
        virtual void openMenu();

        //查看所有预约
        void allOrder();

        //审核预约
        void reviewOrder();
};