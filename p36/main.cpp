#include <iostream>

using namespace std;

//敲桌子游戏，从1开始数到数字100，如果数字个位含有7，或者数字十位含有7，或者数字是7的倍数，程序打印敲桌子，否则直接输出该数字
int main()
{
    int a, b;

    for (size_t i = 1; i <= 100; i++)
    {
        a = i/10;
        b = i%10;
        if (a==7 || b==7 || i%7==0)
        {
            cout<<i<<"\t敲桌子！！！"<<endl;
        }
        else
        {
            cout<<i<<endl;
        }
         
    }
    system("pause");
    return 0;

}
