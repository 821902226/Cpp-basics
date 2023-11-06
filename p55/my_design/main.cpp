#include <iostream>
#include <add.h>

using namespace std;

int main()
{
    int num1 = 10;
    int num2 = 20;
    int sum;
    sum = add(num1, num2);
    cout<<"两个数的总和是："<<sum<<endl;

    system("pause");
    return 0;
}