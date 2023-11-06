#include "Student.h"

Student::Student()
{

}

Student::Student(int id, string name, string password)
{
    this->s_id = id;
    this->name = name;
    this->password = password;

    this->vCom.clear();
    ifstream ifs(COMPUTER_FILE, ios::in);
    Computer c;
    while (ifs>>c.c_id&& ifs>>c.c_maxNum)
    {
        this->vCom.push_back(c);
    }
    ifs.close();
    
}

void Student::openMenu()
{
    cout << "欢迎学生代表：" << this->name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Student::applyOrder()
{
    cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}


	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << this->vCom[0].c_maxNum << endl;
	cout << "2号机房容量：" << this->vCom[1].c_maxNum<< endl;
	cout << "3号机房容量：" << this->vCom[2].c_maxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功！审核中" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->s_id << " ";
	ofs << "stuName:" << this->name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

void Student::myOrder()
{
    Order order;
    if (order.o_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

    for (int i = 0; i < order.o_size; i++)
    {
        if (this->s_id == atoi(order.orderData[i]["stuId"].c_str()))
        {
            cout << "预约日期： 周" << order.orderData[i]["date"];
			cout << " 时段：" << (order.orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << order.orderData[i]["roomId"];
			string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
			if (order.orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (order.orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (order.orderData[i]["status"] == "-1")
			{
				status += "审核未通过，预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
        }
        
    }
    system("pause");
	system("cls");
    
}

void Student::allOrder()
{
    Order order;
    if (order.o_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

    for (int i = 0; i < order.o_size; i++)
    {
        cout << i + 1 << "、 ";
        cout << "预约日期： 周" << order.orderData[i]["date"];
        cout << " 时段：" << (order.orderData[i]["interval"] == "1" ? "上午" : "下午");
        cout << " 学号：" <<order.orderData[i]["stuId"];
        cout << " 姓名：" <<order.orderData[i]["stuName"];
        cout << " 机房：" << order.orderData[i]["roomId"];
        string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
        if (order.orderData[i]["status"] == "1")
        {
            status += "审核中";
        }
        else if (order.orderData[i]["status"] == "2")
        {
            status += "预约成功";
        }
        else if (order.orderData[i]["status"] == "-1")
        {
            status += "审核未通过，预约失败";
        }
        else
        {
            status += "预约已取消";
        }
        cout << status << endl;
    }
        
    system("pause");
	system("cls");
}

void Student::cancelOrder()
{
    Order order;
    if (order.o_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

    vector<int>v;
	int index = 1;
	for (int i = 0; i < order.o_size; i++)
	{
		if (atoi(order.orderData[i]["stuId"].c_str()) == this->s_id)
		{
			if (order.orderData[i]["status"] == "1" || order.orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout <<  index ++  << "、 ";
				cout << "预约日期： 周" << order.orderData[i]["date"];
				cout << " 时段：" << (order.orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房：" << order.orderData[i]["roomId"];
				string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约  -1 预约失败
				if (order.orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (order.orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;

			}
		}
	}

    cout << "请输入取消的记录,0代表返回" << endl;
    int select = 0;
    
    while (true)
    {
        cin>>select;
        if (select>=0&&select<=index)
        {
            if (select == 0)
            {
                break;
            }
            else
            {
                order.orderData[v[select-1]]["status"] = "0";
                order.updateOrder();
                cout<<"成功取消预约！"<<endl;
                break;
            }
            
        }
        cout << "输入有误，请重新输入" << endl;
    }

    system("pause");
    system("cls");
}
