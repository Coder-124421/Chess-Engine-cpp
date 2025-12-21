#include <string>
#include "piece.h"
// #include "board.h"
class Board;
struct Move
{
    int fr, fc;
    int tr, tc;
};
class MoveManager
{
public:
    static Move tomove(std::string, std::string);
    static piece MakeMove(Board &, Move);
    static void Undo(Board &, Move, piece);
};
