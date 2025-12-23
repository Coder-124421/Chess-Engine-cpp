#pragma once
class Board;
enum class COLOR;
class MoveDetector
{
public:
    static bool Moveexist(Board &, COLOR);
};
