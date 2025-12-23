#include "move.h"
#include "board.h"
#include "piece.h"
#include <string>

Move MoveManager::tomove(std::string s, std::string t)
{
    Move move;
    move.fc = s[0] - 'a';
    move.fr = '8' - s[1];
    move.tc = t[0] - 'a';
    move.tr = '8' - t[1];
    return move;
}
piece MoveManager::MakeMove(Board &board, Move move)
{
    piece temp = board.grid[move.fr][move.fc];
    if(temp.type == Piecetype::Pawn){
        if(temp.color==COLOR::White && move.tr == 0 || temp.color== COLOR::Black && move.tr ==7){
            temp.type = Piecetype::Queen;
        } 
    }
    piece toundo = board.grid[move.tr][move.tc];
    board.grid[move.fr][move.fc] = piece(COLOR::None, Piecetype::None);
    board.grid[move.tr][move.tc] = temp;
    return toundo;
}
void MoveManager::Undo(Board &board, Move move, piece toundo)
{
    board.grid[move.fr][move.fc] = board.grid[move.tr][move.tc];
    board.grid[move.tr][move.tc] = toundo;
}