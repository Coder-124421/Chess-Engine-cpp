#pragma once
#include<iostream>
#include<vector>
class Board;
enum class COLOR;
class CheckDetector
{
    public:
   static std:: pair<int,int> KingPos(Board&, COLOR side);
    static bool check(Board &board, COLOR side);
};
