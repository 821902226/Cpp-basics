#pragma once
#include <iostream>

using namespace std;

template<class T>
class MyArray
{
    private:
        T * myArray;
        int capacity;
        int size;
    
    public:
        MyArray(int capacity)
        {
            this->capacity = capacity;
            this->size = 0;
            this->myArray = new T[capacity];
        }

        //拷贝构造函数
        MyArray(const MyArray& array)
        {
            this->capacity = array->capacity;
            this->size = array->size;
            //深拷贝
            this->myArray = new T[this->capacity];
            for (int i = 0; i < this->size; i++)
            {
                this->myArray[i] = array->myArray[i];
            }
            
        }

        MyArray& operator=(const MyArray& array)
        {
            if (this->myArray != NULL)
            {
                delete[] this->myArray;
                myArray = NULL;
            }
            this->capacity = array->capacity;
            this->size = array->size;
            //深拷贝
            this->myArray = new T[this->capacity];
            for (int i = 0; i < this->size; i++)
            {
                this->myArray[i] = array->myArray[i];
            }

            return *this;
            
        }

        //尾插 
        void push_back(const T &element)
        {
            if (this->size<this->capacity)
            {
                this->myArray[size] = element;
                this->size++;
            }
            else{
                cout<<"插入失败，数组容量已满！"<<endl;
            }
            
        }

        //尾删
        void pop_back()
        {
            if (size != 0)
            {
                this->size--;
            }
            else{
                cout<<"删除失败，数组中没有元素!"<<endl;
            }
            
        }

        //通过下标访问元素
        T& operator[](int id)
        {
            return this->myArray[id];
        }

        //返回数组容量
        int getCapacity()
        {
            return this->capacity;
        }

        //返回数组大小
        int getSize()
        {
            return this->size;
        }

        ~MyArray()
        {
            if (this->myArray != NULL)
            {
                delete[] this->myArray;
                this->myArray = NULL;
            }
            
        }

};