#include <iostream>
#include <cmath>

using namespace std;

//找出所有三位数字中的水仙花数，例如1^3+5^3+3^3=153
int main()
{
    int num=100;
    int a, b, c;

    cout<<"所有的水仙花数："<<endl;
    do
    {
        a=num/100;  //百位
        b=(num%100)/10; //十位
        c=num%10;   //个位

        int total = pow(a,3)+pow(b,3)+pow(c,3); //遇到问题，为什么把pow(a,3)+pow(b,3)+pow(c,3)放到if语句中得到的结果少了407
        if (total==num)
        {
            cout<<num<<endl;
        }
        num++;
    } while (num<1000);
    
    system("pause");

}