#include <iostream>

using namespace std;

void sort(int * p, int len);

//封装一个函数，利用冒泡排序实现对整型数组的升序排序
int main()
{
    int arr[] = {4, 6, 1, 9, 0, 2, 7, 3, 8, 5};
    int len = sizeof(arr)/sizeof(arr[0]);

    sort(arr, len);

    cout<<"排序后的结果："<<endl;
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i]<<endl;
    }

    system("pause");
    return 0;
}

void sort(int * p, int len) //也可以写成void sort(int p[], int len)
{
    int temp=0;
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-1-i; j++)
        {
            //两种方法都可以
            //方法一
            /*if (*(p+j)>*(p+j+1))
            {
                temp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = temp;
            }*/
            
            //方法二
            if (p[j]>p[j+1])
            {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
        
    }
    
}