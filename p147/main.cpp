#include <iostream>
#include <string>
#include "System.h"
#include "Staff.h"
#include "Boss.h"
#include "Manager.h"
#include "Employee.h"

using namespace std;

//基于多态的职工管理系统（包含老板、经理、普通员工）
int main()
{
    System system;
    int code = 0;

    while (true)
    {
        system.showMenu();
        cout<<"输入您的选择： ";
        cin>>code;

        if (code == 0)  //退出系统
        {
            system.exitSystem();
        }
        else if (code == 1)
        {
            system.addStaff();
        }
        else if (code == 2)
        {
            system.showStaffInfo();
        }
        else if (code == 3)
        {
            system.deleteStaff();
        }
        else if (code == 4)
        {
            system.modifyStaff();
        }
        else if (code == 5)
        {
            system.searchStaff();
        }
        else if (code == 6)
        {
            system.sortStaff();
        }
        else if (code ==7)
        {
            system.cleanFile();
        }
    }

    return 0;
}