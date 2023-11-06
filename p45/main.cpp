#include <iostream>

using namespace std;

//实现数组元素的逆置
int main()
{
    int arr[] = {1, 3, 2, 5, 4};
    int temp = 0;
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < size/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
    
    cout<<"逆置后的数组："<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    system("pause");
    return 0;
}