#pragma once
#include <iostream>
#include <deque>
#include <string>

using namespace std;

template<class T>
class Player
{
    public:
        string name;
        deque<T> scores;

        Player(string name, deque<T> scores)
        {
            this->name = name;
            this->scores = scores;
        }
 };