#include <iostream>
#include <string>
#include <list>

using namespace std;

//List容器实现自定义类型的排序

class Person
{
    public:
        string name;
        int age;
        float height;

        Person(){}
    
        Person(string name, int age, float height)
        {
            this->name = name;
            this->age = age;
            this->height = height;
        }
};

void printList(list<Person> l)
{
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout<<(*it).name<<" "<<(*it).age<<" "<<(*it).height<<endl;
    }
    
}

//建立自己的排序规则
bool myCompare(Person p1, Person p2)
{
    if (p1.age == p2.age)
    {
        return p1.height>p2.height;  
    }
    else
    {
        return p1.age<p2.age;
    } 
}

int main()
{
    list<Person> l;
    Person p1("刘一", 15, 167);
    Person p2("杨二", 18, 173);
    Person p3("张三", 16, 159);
    Person p4("李四", 17, 163);
    Person p5("王五", 16, 167);
    Person p6("赵六", 16, 178);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);

    cout<<"排序前："<<endl;
    printList(l);
    l.sort(myCompare);
    cout<<"排序后："<<endl;
    printList(l);

    system("pause");
    return 0;
}