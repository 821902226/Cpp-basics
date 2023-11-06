#include "SpeechManager.h"


SpeechManager::SpeechManager()
{
    this->initSpeech();
    this->createSpeaker();
    this->readRecord();
}

void SpeechManager::initSpeech()
{
    this->v1.clear();
    this->v2.clear();
    this->vVectory.clear();
    this->speaker.clear();
    this->index = 1;
    this->record.clear();
}

void SpeechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        Speaker speaker;

        string name = "选手";
        name += nameSeed[i];
        speaker.name = name;

        for (int j = 0; j < 2; j++)
        {
            speaker.score[j] = 0;
        }
        
        this->v1.push_back(i+10001);

        this->speaker.insert(pair<int, Speaker>(i+10001, speaker));
    }
    
}

void SpeechManager::startSpeech()
{
    //第一轮比赛
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechScore();
    //3、显示晋级结果
    this->showScore();

    this->index++;
    //第二轮比赛
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechScore();
    //3、显示最终结果
    this->showScore();
    //4、保存分数到文件中
    this->saveRecord();

    //比赛结束后重置数据
    this->initSpeech();
    this->createSpeaker();
    this->readRecord();

    cout<<"本届比赛结束！"<<endl;
    system("pause");
    system("cls");
}

void SpeechManager::speechDraw()
{
    cout<<"第"<<this->index<<"轮选手正在抽签"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"抽签后演讲顺序如下："<<endl;

    srand(time(0));
    if (this->index == 1)
    {
        random_shuffle(this->v1.begin(), this->v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout<<*it<<" ";
        }
        
    }
    else if (this->index == 2)
    {
        random_shuffle(this->v2.begin(), this->v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout<<*it<<" ";
        }
    }
    cout<<endl;
    cout<<"---------------------"<<endl;
    system("pause");
}

void SpeechManager::speechScore()
{
    cout<<"正在进行第"<<this->index<<"轮比赛"<<endl;

    vector<int> v;
    if (this->index == 1)
    {
        v = this->v1;
    }
    else if (this->index == 2)
    {
        v = this->v2;
    }
    
    deque<double> scores;
    multimap<double, int, greater<double>> groupScore;
    int num = 0;
    srand(time(0));
    for (auto it = v.begin(); it != v.end(); it++)
    {
        num++;
        for (int j = 0; j < 10; j++)
        {
            double score =  (rand()%401+600)/10.f;
            scores.push_back(score);
        }
        sort(scores.begin(), scores.end(), greater<double>());
        scores.pop_back();  //去掉最高分
        scores.pop_front(); //去掉最低分

        double sum = accumulate(scores.begin(), scores.end(), 0.f);
        double avg = (double)sum/scores.size();

        this->speaker[*it].score[this->index-1] = avg;  //给每个选手赋分

        groupScore.insert(make_pair(avg, *it));

        if (num%6==0)
        {
            cout<<"第"<<num/6<<"小组比赛名次"<<endl;
            for (auto it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout<<"编号："<<it->second<<" 姓名："<<this->speaker[it->second].name<<" 得分："<<this->speaker[it->second].score[this->index-1]<<endl;
            }

            auto it= groupScore.begin();
            for (int m = 0; m < 3; m++)
            {
                if (this->index == 1)
                {
                    this->v2.push_back(it->second);
                }
                else if (this->index == 2)
                {
                    this->vVectory.push_back(it->second);
                }
                it++;
            }
            
            groupScore.clear();
        }
        
    }
    cout<<"第"<<this->index<<"轮比赛结束"<<endl;
    system("pause");
}

void SpeechManager::showScore()
{
    cout<<"第"<<this->index<<"轮晋级选手的信息："<<endl;
    vector<int> v;
    if (this->index == 1)
    {
        v = this->v2;
    }
    else if (this->index == 2)
    {
        v = this->vVectory;
    }
    
    //打印信息
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout<<"编号："<<*it<<" 姓名："<<this->speaker[*it].name<<" 得分："<<this->speaker[*it].score[this->index-1]<<endl;
    }
    system("pause");
    
}

void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("./record.csv", ios::out | ios::app);

    for (auto it = this->vVectory.begin(); it != vVectory.end(); it++)
    {
        ofs<<*it<<","<<this->speaker[*it].score[1]<<",";
    }
    ofs<<endl;
    ofs.close();
    this->fileIsEmpty = false;
    cout<<"记录保存成功!"<<endl;
}

void SpeechManager::readRecord()
{
    ifstream ifs;
    ifs.open("./record.csv", ios::in);
    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        //cout<<"文件不存在!"<<endl;
        ifs.close();
        return;
    }
    
    char ch;
    ifs>>ch;
    if (ifs.eof())
    {
        this->fileIsEmpty = true;
        //cout<<"文件为空！"<<endl;
        ifs.close();
        return;
    }

    this->fileIsEmpty = false;
    ifs.putback(ch);

    string data;
    int i = 0;
    while (ifs>>data)
    {
        i++;
        vector<string> info;
        info.clear();
        int pos = -1;
        int start = 0;
        while (true)
        {
            pos = data.find(",", start);
            if (pos == -1)
            {
                break;
            }
            
            string temp = data.substr(start, pos-start);
            start = pos+1;
            info.push_back(temp);
        }
        this->record.insert(pair<int, vector<string>>(i, info));   
    }
    
}

void SpeechManager::showRecord()
{
    if (this->fileIsEmpty)
    {
        cout<<"文件不存在或者为空！"<<endl;
    }
    
    for (map<int, vector<string>>::iterator it = this->record.begin(); it != this->record.end(); it++)
    {
        cout<<"第"<<it->first<<"届比赛："<<"冠军编号--"<<it->second[0]<<" 得分--"<<it->second[1]<<
        " 亚军编号--"<<it->second[2]<<" 得分--"<<it->second[3]<<
        " 季军编号--"<<it->second[4]<<" 得分--"<<it->second[5]<<endl;
    }
    system("pause");
    system("cls");
}

void SpeechManager::clearRecord()
{
    cout<<"确认清空？"<<endl;
    cout<<"1、确认"<<endl;
    cout<<"2、取消"<<endl;

    int select = 2;
    cin>>select;
    if (select == 1)
    {
        ofstream ofs;
        ofs.open("./record.csv", ios::trunc);
        ofs.close();
        this->initSpeech();
        this->createSpeaker();
        this->readRecord();
        cout<<"清空成功！"<<endl;
    }
    system("pause");
    system("cls");
}

void SpeechManager::showMenu()
{
    cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem()
{
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);
}

SpeechManager::~SpeechManager()
{

}
