#include <iostream>

using namespace std;

//五只小猪称体重，打印最重的小猪体重
int main()
{
    int arr[5] = {300, 350, 200, 400, 250};
    int max_pig = 0;

    for (size_t i = 0; i < 5; i++)
    {
        if (arr[i]>max_pig)
        {
            max_pig = arr[i];
        }
        
    }

    cout<<"最重的小猪体重是："<<max_pig<<"kg"<<endl;

    system("pause");
    return 0;
    
}