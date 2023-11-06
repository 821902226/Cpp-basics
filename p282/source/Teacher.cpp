#include "Teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int id, string name, string password)
{
    this->t_id = id;
    this->name = name;
    this->password = password;
}

void Teacher::openMenu()
{
    cout << "欢迎教师：" << this->name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Teacher::allOrder()
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

void Teacher::reviewOrder()
{
    Order order;
    if (order.o_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
    cout << "待审核的预约记录如下：" << endl;
    vector<int>v;
	int index = 1;
	for (int i = 0; i < order.o_size; i++)
	{
		if (atoi(order.orderData[i]["stuId"].c_str()) == this->t_id)
		{
			if (order.orderData[i]["status"] == "1")    // 0 取消的预约   1 审核中   2 已预约  -1 预约失败
			{
				v.push_back(i);
				cout <<  index ++  << "、 ";
				cout << "预约日期： 周" << order.orderData[i]["date"];
				cout << " 时段：" << (order.orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房：" << order.orderData[i]["roomId"];
				string status = " 状态： 审核中";  
				cout << status << endl;
			}
		}
	}

    if (index == 1)
    {
        cout<<"没有待审核的预约记录!"<<endl;
    }

    cout << "请输入要审核的记录,0代表返回" << endl;
    int select = 0;
    int code = 0;
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
                cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
                cin>>code;
                if (code == 1)
                {
                    order.orderData[v[select-1]]["status"] = "2";
                }
                else if (code == 2)
                {
                    order.orderData[v[select-1]]["status"] = "-1";
                }
                order.updateOrder();
                cout<<"审核完毕！"<<endl;
                break;
            }
            
        }
        cout << "输入有误，请重新输入" << endl;
    }
    
    system("pause");
    system("cls");
}