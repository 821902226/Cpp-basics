#include <iostream>
#include <string>

using namespace std;

//设计一个英雄结构体，包含姓名、年龄、性别；创建结构体数组，存放5名英雄；通过冒泡排序，根据年龄对英雄升序排序。
struct hero
{
    string name;
    int age;
    string gender;
};

void sort(struct hero person[], int size)
{
    struct hero temp;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (person[j].age>person[j+1].age)
            {
                temp = person[j];
                person[j] = person[j+1];
                person[j+1] = temp;
            }
            
        }
        
    }
}

int main()
{
    struct hero person[5];
    string name[5] = {"刘备", "关羽", "张飞", "赵云", "貂蝉"};
    int age[5] = {23, 22, 20, 21, 19};
    string gender[5] = {"男", "男", "男", "男", "女"};
    for (int i = 0; i < 5; i++)
    {
        person[i].name = name[i];
        person[i].age = age[i];
        person[i].gender = gender[i];
    }

    //按照年龄升序排列
    int size = sizeof(person)/sizeof(person[0]);
    sort(person, size);

    //排序后的结果打印
    for (size_t i = 0; i < size; i++)
    {
        cout<<person[i].name<<"\t"<<person[i].age<<"\t"<<person[i].gender<<endl;
    }
    
    

}