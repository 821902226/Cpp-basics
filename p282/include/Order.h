#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "globalFile.h"

using namespace std;

class Order
{
    public:
        int o_size;
        map<int, map<string, string>> orderData;

        Order();

        void updateOrder();

};