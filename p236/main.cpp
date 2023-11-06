#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <ctime>

using namespace std;

//员工分组放入到multimap中

class Person
{
    public:
        string name;

        Person(){}
    
        Person(string name)
        {
            this->name = name;
        }
};

int main()
{
    vector<Person> v;
    Person p1("刘一");
    Person p2("杨二");
    Person p3("张三");
    Person p4("李四");
    Person p5("王五");
    Person p6("赵六");
    Person p7("孟七");
    Person p8("甘八");
    Person p9("陈九");
    Person p10("金十");
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);
    v.push_back(p7);
    v.push_back(p8);
    v.push_back(p9);
    v.push_back(p10);

    multimap<int, Person> info;
    srand(time(0));
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        int id =  rand()%3;   //部门划分
        info.insert(pair<int, Person> (id, *it));
    }

    //分部门显示员工信息(方法一)
    string dept[] = {"策划", "美术", "研发"};
    for (int i = 0; i < 3; i++)
    {
        for (multimap<int, Person>::iterator it = info.begin(); it != info.end(); it++)
        {
            if (it->first == i)
            {
                cout<<"部门："<<dept[i]<<" 姓名："<<it->second.name<<endl;
            }
            
        }
        
    }

    cout<<"---------------------------"<<endl;

    //分部门显示员工信息(方法二)
    multimap<int, Person>::iterator it0 = info.find(0);
    for (unsigned i = 0; i < info.count(0); i++)
    {
        cout<<"部门："<<dept[0]<<" 姓名："<<it0->second.name<<endl;
        it0++;
    }
    multimap<int, Person>::iterator it1 = info.find(1);
    for (unsigned i = 0; i < info.count(1); i++)
    {
        cout<<"部门："<<dept[1]<<" 姓名："<<it1->second.name<<endl;
        it1++;
    }
    multimap<int, Person>::iterator it2 = info.find(2);
    for (unsigned i = 0; i < info.count(2); i++)
    {
        cout<<"部门："<<dept[2]<<" 姓名："<<it2->second.name<<endl;
        it2++;
    }
    
    
    
    system("pause");
    return 0;
}