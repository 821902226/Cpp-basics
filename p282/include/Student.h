#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "globalFile.h"
#include "Computer.h"
#include "Identity.h"
#include "Order.h"

using namespace std;

class Student: public Identity
{
    public:
        int s_id;

        vector<Computer> vCom;
        
        Student();

        Student(int id, string name, string password);

        //打开菜单
        virtual void openMenu();

        //申请预约
        void applyOrder();

        //我的预约
        void myOrder();

        //所有预约
        void allOrder();

        //取消预约
        void cancelOrder();
   
};
