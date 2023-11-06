#include <iostream>

using namespace std;

//输入三头猪的体重，找出最大的体重并输出
int main()
{
    float pig1, pig2, pig3, max_pig;
    cout<<"输入三头猪的体重："<<endl;
    cin>>pig1>>pig2>>pig3;

    /*if (pig1>pig2)
    {
        max_pig = pig1;
        if (pig3>max_pig)
        {
            max_pig = pig3;
        }
        
    }
    else
    {
        max_pig = pig2;
        if (pig3>max_pig)
        {
            max_pig = pig3;
        }
    }*/

    //三目运算符
    max_pig = pig1>pig2?pig1:pig2;
    max_pig = pig3>max_pig?pig3:max_pig;

    cout<<"三头猪的最大体重为："<<max_pig<<endl;
    system("pause");

    return 0;
    
}