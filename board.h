#pragma once
#include<vector>
#include "piece.h"
class Board{
    public:
    std:: vector<std::vector<piece>>grid;
    Board();
    void reset();
    // void show();
};
