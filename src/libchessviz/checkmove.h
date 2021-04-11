#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int check_move(
        char** area,
        string move,
        vector<char>& first_move,
        vector<char>& second_move);
bool move_check_area(vector<char> move, int position);
bool check_figure(string move, int position);
