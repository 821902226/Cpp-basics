#include <iostream>
#include <string>

using namespace std;

//函数模版 对不同类型的数组进行从大到小排序(选择排序)
template<typename T>
void sort(T *array, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        int maxIndex = i;
        for (int j = i+1; j < size; j++)
        {
            if (array[j]>array[maxIndex])
            {
                maxIndex = j;
            }
        }
        if(maxIndex != i)
        {
            T temp = array[i];
            array[i] = array[maxIndex];
            array[maxIndex] = temp;
        }
    }
}

int main()
{
    int array[] = {2, 5, 1, 7, 4, 3, 6};
    char charArr[] = "fdgcabe";
    int size = sizeof(array)/sizeof(array[0]);
    int c_size = sizeof(charArr)/sizeof(charArr[0]);
    sort<int>(array, size);
    for (size_t i = 0; i < size; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;

    sort(charArr, c_size);
    for (size_t i = 0; i < c_size; i++)
    {
        cout<<charArr[i]<<" ";
    }
    cout<<endl;
    
}