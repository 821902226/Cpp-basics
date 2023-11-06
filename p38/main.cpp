#include <iostream>

using namespace std;

//打印一张乘法口诀表
int main()
{
    for (size_t i = 1; i <= 9; i++)
    {
        for (size_t j = 1; j <= i; j++)
        {
            cout<<j<<"*"<<i<<"="<<i*j<<"\t";
        }
        cout<<endl;
        
    }
    
    system("pause");
    return 0;
}