#include <iostream>
#include <string>

using namespace std;

#define MAX 1000

//通讯录管理系统

//联系人结构体
struct Person
{
    string name;
    int gender; //0男，1女
    int age;
    string phone;
    string addr;
};

//通讯录结构体
struct AddressBook
{
    int size;
    Person personArray[MAX];
}; 

void showMenu()
{
    cout<<"*********************"<<endl;
    cout<<"***"<<" 1、添加联系人 "<<"***"<<endl;
    cout<<"***"<<" 2、显示联系人 "<<"***"<<endl;
    cout<<"***"<<" 3、删除联系人 "<<"***"<<endl;
    cout<<"***"<<" 4、查找联系人 "<<"***"<<endl;
    cout<<"***"<<" 5、修改联系人 "<<"***"<<endl;
    cout<<"***"<<" 6、清空联系人 "<<"***"<<endl;
    cout<<"***"<<" 0、退出通讯录 "<<"***"<<endl;
    cout<<"*********************"<<endl;
}

void addPerson(AddressBook * book)
{
    cout<<"请输入姓名："<<endl;
    cin>>book->personArray[book->size].name;
    cout<<"请输入性别：0男 1女"<<endl;
    cin>>book->personArray[book->size].gender;
    cout<<"请输入年龄："<<endl;
    cin>>book->personArray[book->size].age;
    cout<<"请输入联系电话："<<endl;
    cin>>book->personArray[book->size].phone;
    cout<<"请输入住址："<<endl;
    cin>>book->personArray[book->size].addr;

    book->size++;
    cout<<"添加成功。"<<endl;
}

void showPerson(const AddressBook * book)
{
    if (book->size == 0)
    {
        cout<<"通讯录为空。"<<endl;
    }
    else{
        cout<<"所有联系人："<<endl;
        for (int i = 0; i < book->size; i++)
        {
            cout<<i+1<<" "<<book->personArray[i].name<<" "<<(book->personArray[i].gender==0?"男":"女")<<" "
            <<book->personArray[i].age<<" "<<book->personArray[i].phone<<" "<<book->personArray[i].addr<<endl;
        }
        cout<<"显示完毕！"<<endl;
    }
}

//检测联系人是否存在，若存在则返回其在数组中的位置，否则返回-1。
int isExist(const AddressBook * book, string name)
{
    for (size_t i = 0; i < book->size; i++)
    {
        if (book->personArray[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

//删除指定的联系人
void deletePerson(AddressBook * book)
{
    string name;
    cout<<"输入要删除的联系人的姓名："<<endl;
    cin>>name;
    int id = isExist(book, name);
    if (id == -1)
    {
        cout<<"查无此人！！！"<<endl;
    }
    else{
        for (int i = id; i < book->size; i++)
        {
            book->personArray[i] = book->personArray[i+1];
        } 
        book->size--;
        cout<<"删除成功！！！"<<endl;
    }
}

void searchPerson(AddressBook * book)
{
    string name;
    cout<<"输入要查找的联系人的姓名："<<endl;
    cin>>name;
    int id = isExist(book, name);
    if (id == -1)
    {
        cout<<"查无此人！！！"<<endl;
    }
    else{
        cout<<book->personArray[id].name<<" "<<(book->personArray[id].gender==0?"男":"女")<<" "
            <<book->personArray[id].age<<" "<<book->personArray[id].phone<<" "<<book->personArray[id].addr<<endl;
    }
}

void alterPerson(AddressBook * book)
{
    string name;
    cout<<"输入要修改的联系人的姓名："<<endl;
    cin>>name;
    int id = isExist(book, name);
    if (id == -1)
    {
        cout<<"查无此人！！！"<<endl;
    }
    else{
        cout<<"请输入姓名："<<endl;
        cin>>book->personArray[id].name;
        cout<<"请输入性别：0男 1女"<<endl;
        cin>>book->personArray[id].gender;
        cout<<"请输入年龄："<<endl;
        cin>>book->personArray[id].age;
        cout<<"请输入联系电话："<<endl;
        cin>>book->personArray[id].phone;
        cout<<"请输入住址："<<endl;
        cin>>book->personArray[id].addr;
        cout<<"修改成功！！！"<<endl;
    }
}

void clearPerson(AddressBook * book)
{
    //逻辑清空
    book->size = 0;
    cout<<"清除成功！！！"<<endl;
}

int main()
{
    int code = 0;

    //创建通讯录
    AddressBook book;
    book.size=0;
    AddressBook *book_ptr = &book;

    while (true)
    {
        showMenu();
        cin>>code;
        if (code == 0)  //退出通讯录
        {
            cout<<"欢迎下次使用！"<<endl;
            break;
        }
        else if (code == 1) //添加联系人
        {
            addPerson(book_ptr);
        }
        else if (code == 2) //显示联系人
        {
            showPerson(book_ptr);
        }
        else if(code == 3)  //删除联系人
        {
            deletePerson(book_ptr);
        }
        else if(code == 4) //查找联系人
        {
            searchPerson(book_ptr);
        }
        else if(code == 5)  //修改联系人
        {
            alterPerson(book_ptr);
        }
        else if (code == 6) //清空联系人
        {
            clearPerson(book_ptr);
        }
        
    }

    return 0;

}