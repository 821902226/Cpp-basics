#include <iostream>
#include <string>

using namespace std;

//多态实现计算器

class Calculator
{
    public:
        float n1, n2;
        virtual float getResult()
        {
            return 0;
        }
};

class Add: public Calculator
{
    public:
        Add(float n1, float n2)
        {
            this->n1 = n1;
            this->n2 = n2;
        }
        float getResult()
        {
            return n1+n2;
        }
};

class Substract: public Calculator
{
    public:
        Substract(float n1, float n2)
        {
            this->n1 = n1;
            this->n2 = n2;
        }
        float getResult()
        {
            return n1-n2;
        }
};

class Multiply: public Calculator
{
    public:
        Multiply(float n1, float n2)
        {
            this->n1 = n1;
            this->n2 = n2;
        }
        float getResult()
        {
            return n1*n2;
        }
};

class Divide: public Calculator
{
    public:
        Divide(float n1, float n2)
        {
            this->n1 = n1;
            this->n2 = n2;
        }
        float getResult()
        {
            return n1/n2;
        }
};

int main()
{
    //多态：父类指针或者引用指向子类对象
    //加
    Calculator * cal = new Add(3, 5);
    cout<<"加法结果："<<cal->getResult()<<endl;

    //减
    cal = new Substract(8, 4);
    cout<<"减法结果："<<cal->getResult()<<endl;

    //乘
    cal = new Multiply(3, 5);
    cout<<"乘法结果："<<cal->getResult()<<endl;

    //除
    cal = new Divide(9, 3);
    cout<<"除法结果："<<cal->getResult()<<endl;

    //引用加
    Add add(1,3);
    Calculator &calculate = add;
    cout<<"父类引用子类对象--加法："<<calculate.getResult()<<endl;

    return 0;
}