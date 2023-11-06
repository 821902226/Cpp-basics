#include <iostream>
#include <string>

using namespace std;

class Student{
    public:
        string name;
        int id;

        void setName()
        {
            cout<<"输入学生的姓名："<<endl;
            cin>>name;
        }

        void setId()
        {
            cout<<"输入学生的学号："<<endl;
            cin>>id;
        }

        void showName()
        {
            cout<<"姓名："<<name<<endl;
        }

        void showId()
        {
            cout<<"学号："<<id<<endl;
        }

};

int main()
{
    Student stu;
    //设置学生姓名和学号
    stu.setName();
    stu.setId();

    //显示学生的姓名和学号
    stu.showName();
    stu.showId();

}