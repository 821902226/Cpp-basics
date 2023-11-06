#include <iostream>

using namespace std;

//冒泡排序（升序）
//1、比较相邻的元素， 如果第一个比第二个大，就交换它们两个
//2、对每一对相邻的元素执行相同的操作，执行完毕后可以找到第一个最大值
//3、重复以上步骤，每次比较次数减1
int main()
{
    int array[]={4, 2, 8, 0, 5, 7, 1, 3, 9, 6};
    int size = sizeof(array)/sizeof(array[0]);
    int temp=0;

    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            if (array[j]>array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp; 
            }
            
        }
        
    }
    
    cout<<"重新排序后的数组：";
    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    system("pause");

    return 0;
}