#pragma once
class Board;
struct Move;
enum class COLOR;
class Validator
{
public:
  static bool isLegalMove(Board &chess, Move move, COLOR side);
      static void castle(Board &board, COLOR &side,bool x, std:: vector<bool>&state);
};
