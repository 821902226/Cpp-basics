#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <ctime>
#include <random>
#include <fstream>
#include "Speaker.h"
using namespace std;

class SpeechManager
{
public:
    vector<int> v1;  //第一轮参赛的选手编号
    vector<int> v2;  //第二轮参赛的选手编号
    vector<int> vVectory;    //最终获胜的选手编号
    map<int, Speaker> speaker;   //参赛选手
    bool fileIsEmpty;   //文件是否为空
    map<int, vector<string>> record;    //往届比赛记录
    int index;  //比赛轮次

    SpeechManager();

    void initSpeech();

    //比赛开始
    void startSpeech();

    //创建选手
    void createSpeaker();

    //抽签决定演讲顺序
    void speechDraw();

    //比赛打分
    void speechScore();

    //晋级选手的信息
    void showScore();

    //保存获胜选手的记录到csv文件
    void saveRecord();

    //读取记录
    void readRecord();

    //显示比赛记录
    void showRecord();

    //清空比赛记录
    void clearRecord();

    //展示菜单
    void showMenu();

    //退出系统
    void exitSystem();

    ~SpeechManager();
};