#include <iostream>
#include <string>
#include <vector>
#include <Player.hpp>
#include <random>
#include <time.h>
#include <algorithm>
using namespace std;

int main()
{
    string name[5] = {"Noah", "Liam", "Oliver", "Mateo", "Ethan"};
    vector<Player<int>> players;

    deque<int> scores;
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        scores.clear();
        for (int j = 0; j < 10; j++)
        {   
            scores.push_back(rand()%61+40);    //打分：分数0-10
        }
        sort(scores.begin(), scores.end());
        Player<int> p(name[i], scores);
        players.push_back(p);
    }

    for (int i = 0; i < players.size(); i++)
    {
        players[i].scores.pop_front();
        players[i].scores.pop_back();
        int sum = 0;
        for (int j = 0; j < players.size()-2; j++)
        {
            sum += players[i].scores[i];
        }
        int average = sum/(players.size()-2);
        cout<<"第"<<i<<"个选手的平均分是："<<average<<endl;
    }
    
    system("pause");
    return 0;
}