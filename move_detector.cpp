#include "board.h"
#include "move_detector.h"
#include "validity.h"
#include "check_detector.h"
#include "move.h"
#include <iostream>
bool MoveDetector::Moveexist(Board &board, Color side)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board.grid[i][j].color == side)
            {
                for (int i1 = 0; i1 < 8; i1++)
                {
                    for (int j1 = 0; j1 < 8; j1++)
                    {
                        if (board.grid[i1][j1].color == side)
                            continue;
                        Move move;
                        move.fr = i, move.fc = j;
                        move.tr = i1, move.tc = j1;
                        if (Validator::isLegalMove(board, move, side))
                        {
                            piece toundo = MoveManager::MakeMove(board, move);
                            if (!(CheckDetector::check(board, side)))
                            {
                                MoveManager::Undo(board, move, toundo);
                                return true;
                            }
                            MoveManager::Undo(board, move, toundo);
                        }
                    }
                }
            }
        }
    }
    return false;
}