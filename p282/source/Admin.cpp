#include "Admin.h"

Admin::Admin()
{

}

Admin::Admin(string name, string password)
{
    this->name = name;
    this->password = password;

    this->initVector();
	cout<<this->vStu.size()<<" "<<this->vTea.size()<<endl;
}

void Admin::initVector()
{
	this->vStu.clear();
    this->vTea.clear();

    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
	{
		cout << "学生文件读取失败" << endl;
		return;
	}
    
	Student s;
	while (ifs >> s.s_id && ifs >> s.name &&  ifs >> s.password)
	{
		this->vStu.push_back(s);
	}
    ifs.close();

	//读取老师文件信息
	ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open())
	{
		cout << "老师文件读取失败" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.t_id && ifs >> t.name &&  ifs >> t.password)
	{
		this->vTea.push_back(t);
	}
	ifs.close();

	//获取机房信息
	ifs.open(COMPUTER_FILE, ios::in);

	Computer c;
	while (ifs >> c.c_id && ifs >> c.c_maxNum)
	{
		this->vCom.push_back(c);
	}

	ifs.close();
}

bool Admin::checkRepeat(int id, int type)
{

    if (type == 1)
    {
        for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
        {
            if (id == it->s_id)
            {
                return true;
            }
        }
        
    }
    else if (type == 2)
    {
        for (auto it = this->vTea.begin(); it != this->vTea.end(); it++)
        {
            if (id == it->t_id)
            {
                return true;
            }
        }
    } 
    return false;
}

void Admin::openMenu()
{
    cout << "欢迎管理员："<<this->name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Admin::addAccount()
{
    cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;

    string errorTip; //重复错误提示
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号： ";
        errorTip = "学号重复，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
        errorTip = "职工号重复，请重新输入";
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout <<tip << endl;

    while (true)
    {
        cin >> id;
        bool ret = this->checkRepeat(id, select);

        if (ret)
        {
            cout<<errorTip<<endl;
        }
        else
        {
            break;
        }
             
    }

	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->initVector();
}

void printStudent(Student & s)
{
	cout << "学号： " << s.s_id << " 姓名： " << s.name << " 密码：" << s.password << endl;
}

void printTeacher(Teacher & t)
{
	cout << "职工号： " << t.t_id << " 姓名： " << t.name << " 密码：" << t.password << endl;
}

void printComputer(Computer & c)
{
	cout << "机房id号： " << c.c_id << " 最大容量： " << c.c_maxNum << endl;
}

void Admin::showAccount()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select;

	cin>>select;

	if (select==1)
	{
		cout << "所有学生信息如下： " << endl;
		for_each(this->vStu.begin(), this->vStu.end(), printStudent);
	}
	else if (select == 2)
	{
		cout << "所有老师信息如下： " << endl;
		for_each(this->vTea.begin(), this->vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

void Admin::showComputer()
{
	cout << "所有机房信息如下： " << endl;
	for_each(this->vCom.begin(), this->vCom.end(), printComputer);
	system("pause");
	system("cls");
}

void Admin::clearRecord()
{
    ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

