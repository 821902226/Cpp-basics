#include <iostream>
#include <string>
#include "MyArray.hpp"

using namespace std;

int main()
{
    MyArray<int> myArray(10);
    for (int i = 0; i < 5; i++)
    {
        myArray.push_back(i);
    }
    for (int i = 0; i < myArray.getSize(); i++)
    {
        cout<<myArray[i]<<endl;
    }
    cout<<myArray.getCapacity()<<" "<<myArray.getSize()<<endl;

    
    myArray.pop_back();
    for (int i = 0; i < myArray.getSize(); i++)
    {
        cout<<myArray[i]<<endl;
    }
    cout<<myArray.getCapacity()<<" "<<myArray.getSize()<<endl;
    
    
    return 0;
}