#include <iostream>
#include <string>

using namespace std;

//多态实现制作饮品
class Drinking
{
    public:
        void boil()
        {
            cout<<"第一步：煮水"<<endl;
        }

        //纯虚函数
        virtual void brew() = 0;

        void pour()
        {
            cout<<"第三步：倒入杯中"<<endl;
        }
        
        virtual void addMaterial() = 0;
};

class Coffee: public Drinking
{
    public:
        void brew()
        {
            cout<<"第二步：冲泡咖啡"<<endl;
        }

        void addMaterial()
        {
            cout<<"第四步：加糖和牛奶"<<endl;
        }
};

class Tea: public Drinking
{
    public:
        void brew()
        {
            cout<<"第二步：冲泡茶叶"<<endl;
        }

        void addMaterial()
        {
            cout<<"第四步：加柠檬"<<endl;
        }
};


int main()
{
    //多态：父类指针或者引用指向子类对象
    //制作咖啡
    Drinking *drink = new Coffee;
    drink->boil();
    drink->brew();
    drink->pour();
    drink->addMaterial();


    //制作茶
    drink = new Tea;
    drink->boil();
    drink->brew();
    drink->pour();
    drink->addMaterial();

    return 0;
}