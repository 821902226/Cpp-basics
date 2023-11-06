#include <iostream>
#include <string>
#include "SpeechManager.h"

using namespace std;

//基于STL的演讲比赛流程管理系统
int main()
{
    SpeechManager manager;

    int code = 0;

    while (true)
    {
        manager.showMenu();

        cout<<"请输入您的选择："<<endl;
        cin>>code;

        if (code == 0)  //退出系统
        {
            manager.exitSystem();
        }
        else if (code == 1)
        {
            manager.startSpeech();
        }
        else if (code == 2)
        {
            manager.showRecord();
        }
        else if (code == 3)
        {
            manager.clearRecord();
        }
        else
        {
            system("cls");
        }   
    }

    return 0;
}