#include <iostream>
#include <string>
#include <fstream>
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"
#include "globalFile.h"

using namespace std;

//管理员菜单
void adminMenu(Identity* person)
{
	while (true)
	{
		//管理员菜单
		person->openMenu();

		Admin* admin = (Admin*) person;
		int select = 0;

		cin >> select;
        
		if (select == 1)  //添加账号
		{
			cout << "添加账号" << endl;
			admin->addAccount();
		}
		else if (select == 2) //查看账号
		{
			cout << "查看账号" << endl;
			admin->showAccount(); 
		}
		else if (select == 3) //查看机房
		{
			cout << "查看机房" << endl;
			admin->showComputer();
		}
		else if (select == 4) //清空预约
		{
			cout << "清空预约" << endl;
			admin->clearRecord();
		}
		else
		{
			delete person;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生菜单
void studentMenu(Identity* person)
{
	while (true)
	{
		//学生菜单
		person->openMenu();

        Student* stu = (Student*) person;
		int select = 0;

		cin >> select;
        
		if (select == 1)  //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //我的预约
		{
			stu->myOrder();
		}
		else if (select == 3) //所有预约
		{
			stu->allOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete person;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//老师菜单
void teacherMenu(Identity* person)
{
	while (true)
	{
		//老师菜单
		person->openMenu();

        Teacher* tea = (Teacher*) person;
		int select = 0;

		cin >> select;
        
		if (select == 1)  //所有预约
		{
			tea->allOrder();
		}
		else if (select == 2) //审核预约
		{
			tea->reviewOrder();
		}
		else
		{
			delete person;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能
void LoginIn(string fileName, int type)
{

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)	//学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) //教师登录
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;


	if (type == 1)
	{
        //学生登录验证
		int s_id;
        string s_name, s_pwd;

        while (ifs>>s_id && ifs>>s_name && ifs>>s_pwd)
        {
            if (id == s_id && name == s_name && pwd == s_pwd)
            {
                cout<<"学生验证登录成功！"<<endl;
                system("pause");
                system("cls");
                Identity* person = new Student(id, name, pwd);
                //进入学生子菜单
                studentMenu(person);
                return;
            }
            
        }
        
	}
	else if (type == 2)
	{
		//教师登录验证
        int t_id;
        string t_name, t_pwd;

        while (ifs>>t_id && ifs>>t_name && ifs>>t_pwd)
        {
            if (id == t_id && name == t_name && pwd == t_pwd)
            {
                cout<<"教师验证登录成功！"<<endl;
                system("pause");
                system("cls");
                Identity* person = new Teacher(id, name, pwd);
                //进入教师子菜单
                teacherMenu(person);
                return;
            }
            
        }
	}
	else if(type == 3)
	{
		//管理员登录验证
        string a_name, a_pwd;
        while (ifs>>a_name && ifs>>a_pwd)
        {
            if (name == a_name && pwd == a_pwd)
            {
                cout<<"管理员验证登录成功！"<<endl;
                system("pause");
                system("cls");
                Identity *person = new Admin(name, pwd);
                //进入管理员子菜单
                adminMenu(person);
                return;
            }
            
        }
	}
	
	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
	return;
}

//机房预约系统
int main()
{
    int code;

    while (true)
    {
        cout << "======================  欢迎来到机房预约系统  =====================" << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";
        
        cin>>code;

        switch (code)
        {
            case 1: //学生
                LoginIn(STUDENT_FILE, 1);
                break;
            case 2: //老师
                LoginIn(TEACHER_FILE, 2);
                break;
            case 3: //管理员
                LoginIn(ADMIN_FILE, 3);
                break;
            case 0: //退出系统
                cout<<"欢迎下次使用！"<<endl;
                system("pause");
                exit(0);
                break;
            default:
                cout<<"输入有误，请重新输入！"<<endl;
                system("pause");
                system("cls");
                break;
        }
    }

    return 0;
}