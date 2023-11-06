#include "System.h"

System::System()
{
    ifstream ifs;
    ifs.open(FILE, ios::in);

    //文件不存在
    if (!ifs.is_open())
    {
        this->staffNum = 0;
        this->staffSet = NULL;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //文件为空
    char ch;
    ifs>>ch;
    if(ifs.eof())
    {
        this->staffNum = 0;
        this->staffSet = NULL;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //文件中有数据
    this->staffNum = this->getStaffNum();
    this->staffSet = new Staff*[this->staffNum];
    this->fileIsEmpty = false;
    this->initStaff();
}

void System::showMenu()
{
    string info[] = {"退出管理系统", "增加职工信息", "显示职工信息", "删除离职职工", "修改职工信息", "查找职工信息", "按照编号排序", "清空所有文档"};
    cout<<"********************************************"<<endl;
    cout<<"*********"<<"  欢迎使用职工管理系统！  "<<"*********"<<endl;
    for (size_t i = 0; i < sizeof(info)/sizeof(info[0]); i++)
    {
        cout<<"*************"<<"  "<<i<<"."<<info[i]<<"  "<<"*************"<<endl;
    }
    cout<<"********************************************"<<endl;
}

void System::addStaff()
{
    cout<<"输入需要添加的职工数量: ";
    int addNum = 0;
    cin>>addNum;

    if(addNum>0)
    {
        //新空间大小 = 原来记录人数 + 新增人数
        int newSize = this->staffNum + addNum;
        //开辟新空间
        Staff ** newSpace = new Staff*[newSize];
        //将原有数据拷贝到新空间
        if (this->staffSet != NULL)
        {
            for (int i = 0; i < staffNum; i++)
            {
                newSpace[i] = this->staffSet[i];
            }
        }
        //批量添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int deptid;

            cout<<"请输入第"<<i+1<<"个新职工的编号："<<endl;
            cin>>id;
            cout<<"请输入第"<<i+1<<"个新职工的姓名："<<endl;
            cin>>name;
            cout<<"请选择该职工的岗位"<<endl;
            cout<<"1、老板 2、经理 3、普通职工"<<endl;
            cin>>deptid;

            Staff *staff = NULL;
            switch (deptid)
            {
            case 1:
                staff = new Boss(id, name, deptid);
                break;
            case 2:
                staff = new Manager(id, name, deptid);
                break;
            case 3:
                staff = new Employee(id, name, deptid);
                break;
            default:
                break;
            }

            newSpace[this->staffNum+i] = staff;
        }
        delete [] this->staffSet;
        this->staffSet = newSpace;
        this->staffNum = newSize;
        
        this->saveFile();
        this->fileIsEmpty = false;
        cout<<"成功添加"<<addNum<<"名新职工！"<<endl;

    }
    else
    {
        cout<<"输入的数据有误！"<<endl;
    }

}

void System::saveFile()
{
    ofstream ofs;
    ofs.open(FILE, ios::out);

    //将每个人的数据写入到文本文件
    for (int i = 0; i < this->staffNum; i++)
    {
        ofs<<this->staffSet[i]->id<<" "<<this->staffSet[i]->name<<" "<<this->staffSet[i]->deptid<<endl;
    }

    ofs.close();
}

int System::getStaffNum()
{
    ifstream ifs;
    ifs.open(FILE, ios::in);

    int id;
    string name;
    int deptid;
    int size = 0;

    while (ifs>>id && ifs>>name && ifs>>deptid)
    {
        size++;
    }
    
    return size;
}

void System::initStaff()
{
    ifstream ifs;
    ifs.open(FILE, ios::in);
    
    int id;
    string name;
    int deptid;
    Staff *staff = NULL;
    int index = 0;

    while (ifs>>id && ifs>>name && ifs>>deptid)
    {
        switch (deptid)
        {
        case 1:
            staff = new Boss(id, name, deptid);
            break;
        case 2:
            staff = new Manager(id, name, deptid);
            break;
        case 3:
            staff = new Employee(id, name, deptid);
            break;
        default:
            break;
        }
        this->staffSet[index] = staff;
        index++;
    }

    ifs.close();
}

void System::showStaffInfo()
{
    if(this->fileIsEmpty)
    {
        cout<<"文件不存在或记录为空！"<<endl;
    }
    else
    {
        for (int i = 0; i < this->staffNum; i++)
        {
            staffSet[i]->showInfo();
        }
        
    }
}

int System::isExist(int id)
{
    for (int i = 0; i < this->staffNum; i++)
    {
        if (id==this->staffSet[i]->id)
        {
            return i;
        }
    }
    return -1;
}

void System::deleteStaff()
{
    int id;
    cout<<"请输入要删除的职工编号："<<endl;
    cin>>id;
    int index = this->isExist(id);  //职工在数组中的位置
    if(index==-1)
    {
        cout<<"职工不存在！"<<endl;
    }
    else
    {
        //新空间大小 = 原来记录人数 - 1
        int newSize = this->staffNum - 1;
        //开辟新空间
        Staff ** newSpace = new Staff*[newSize];
        //将原有数据拷贝到新空间(不包含要删除的职工)
        for (int i = 0; i < staffNum; i++)
        {
            if (i != index)
            {
                newSpace[i] = this->staffSet[i];
            }
        }
       
        delete [] this->staffSet;
        this->staffSet = newSpace;
        this->staffNum = newSize;
        this->fileIsEmpty = newSize>0?false:true;
        this->saveFile();
        cout<<"删除成功！"<<endl;
    }

}

void System::modifyStaff()
{
    int modifyId;
    cout<<"请输入要修改的职工编号："<<endl;
    cin>>modifyId;
    int index = this->isExist(modifyId);
    if (index == -1)
    {
        cout<<"职工不存在！"<<endl;
    }
    else
    {
        cout<<"查找到"<<modifyId<<"号职工!"<<endl;
        int id;
        string name;
        int deptid;
        Staff * staff = NULL;
        cout<<"输入新的职工编号："<<endl;
        cin>>id;
        cout<<"输入新的职工姓名："<<endl;
        cin>>name;
        cout<<"输入新的职工部门编号："<<endl;
        cout<<"1、老板 2、经理 3、普通职工"<<endl;
        cin>>deptid;

        switch (deptid)
        {
            case 1:
                staff = new Boss(id, name, deptid);
                break;
            case 2:
                staff = new Manager(id, name, deptid);
                break;
            case 3:
                staff = new Employee(id, name, deptid);
                break;
            default:
                break;
        }
        this->staffSet[index] = staff;
        this->saveFile();
        cout<<"修改成功！"<<endl;
    }
    
}

void System::searchStaff()
{
    cout<<"输入查找方式：1、按照职工编号查找 2、按照职工姓名查找"<<endl;
    int method;
    cin>>method;
    if (method==1)
    {
        int searchId;
        cout<<"输入职工编号："<<endl;
        cin>>searchId;
        int index = this->isExist(searchId);
        if (index==-1)
        {
            cout<<"职工不存在！"<<endl;
        }
        else
        {
            this->staffSet[index]->showInfo();
        }
    }
    else if (method == 2)
    {
        string name;
        int num = 0;    //用于标记该名字出现了几次
        cout<<"输入职工姓名："<<endl;
        cin>>name;
        for (int i = 0; i < this->staffNum; i++)
        {
            if (name == this->staffSet[i]->name)
            {
                this->staffSet[i]->showInfo();
                num++;
            }
        }
        if (num == 0)
        {
            cout<<"职工不存在！"<<endl;
        }   
    }  
}

void System::sortStaff()
{
    if (this->fileIsEmpty)
    {
        cout<<"文件不存在或者为空！"<<endl;
    }
    else
    {
        cout<<"请选择排序方式："<<endl;
        cout<<"1、按职工号进行升序 2、按职工号进行降序"<<endl;
        int method;
        cin>>method;
        if (method == 1)
        {
            Staff * staff = NULL;
            for (int i = 0; i < this->staffNum-1; i++)  //冒泡排序 升序
            {
                for (int j = 0; j < this->staffNum-i-1; j++)
                {
                    if (this->staffSet[j]->id>this->staffSet[j+1]->id)
                    {
                        staff = this->staffSet[j];
                        this->staffSet[j] = this->staffSet[j+1];
                        this->staffSet[j+1] = staff;
                    }
                }   
            } 
        }
        else if (method == 2)
        {
            Staff * staff = NULL;
            for (int i = 0; i < this->staffNum-1; i++)  //冒泡排序 降序
            {
                for (int j = 0; j < this->staffNum-i-1; j++)
                {
                    if (this->staffSet[j]->id<this->staffSet[j+1]->id)
                    {
                        staff = this->staffSet[j];
                        this->staffSet[j] = this->staffSet[j+1];
                        this->staffSet[j+1] = staff;
                    }
                }   
            }
        }
        this->saveFile();
        cout<<"排序完成！"<<endl;
    }
}

void System::cleanFile()
{
    int sure = 2;
    cout<<"是否清空文件？"<<endl;
    cout<<"1、是\t2、否"<<endl;
    cin>>sure;
    if (sure == 1)
    {
        this->staffSet = NULL;
        this->staffNum = 0;
        this->fileIsEmpty = true;
        this->saveFile();
        cout<<"成功清空所有数据！"<<endl;
    }
}

void System::exitSystem()
{
    cout<<"欢迎下次使用！"<<endl;
    exit(0);
}

System::~System()
{
    if(this->staffSet != NULL)
    {
        delete [] this->staffSet;
        this->staffSet = NULL;
    }
}