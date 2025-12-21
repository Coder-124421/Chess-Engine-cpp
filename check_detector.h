#pragma once
class Board;
enum class Color;
class CheckDetector
{
public:
    static bool check(Board &board, Color side);
};
