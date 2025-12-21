#include "board.h"
#include "validity.h"
#include "move.h"
#include <bits/stdc++.h>
using namespace std;
bool Validator::isLegalMove(Board &chess, Move move, Color side)
{
    if (move.fr < 0 || move.fr > 7 || move.fc < 0 || move.fc > 7 || move.tr < 0 || move.tr > 7 || move.tc < 0 || move.tc > 7)
        return false;

    Color opp = (side == Color::White) ? Color::Black : Color::White;
    piece current = chess.grid[move.fr][move.fc]; // current position
    piece final = chess.grid[move.tr][move.tc];   // final position
    if (current.type == Piecetype::None)
        return false;
    if ((current.color == opp))
        return false;
    if (move.fr == move.tr && move.fc == move.tc)
        return false;
    if (final.color == side)
        return false;
    switch (current.type)
    {
    case Piecetype::Pawn:
    {
        if (((move.tr == move.fr - 1) && (side == Color::White)) || ((side == Color::Black) && (move.tr == move.fr + 1)))
        {
            if (move.tc == move.fc)
            {
                if (final.type != Piecetype::None)
                    return false;
            } // one square move;
            else if (abs(move.tc - move.fc) == 1)
            {
                if ((final.color == Color::None))
                    return false;
            }
            else
                return false;
        }
        else if (abs(move.tr - move.fr) == 2 && move.tc == move.fc)
        {
            if ((side == Color::White) && (!(move.fr == 6 && move.tr == move.fr - 2) || chess.grid[move.fr - 1][move.fc].type != Piecetype::None))
                return false;
            else if ((side == Color::Black) && (!(move.fr == 1 && move.tr == move.fr + 2) || chess.grid[move.fr + 1][move.fc].type != Piecetype::None))
                return false;
            if (chess.grid[move.tr][move.tc].type != Piecetype::None)
                return false;
        } // pawn to two square from its starting square
        else
            return false;
    }
    break;
    case Piecetype::Rook:
    {
        if (move.fr != move.tr && move.fc != move.tc)
            return false;
        int u = move.fr, v = move.tr, same = move.fc;
        if (move.fr == move.tr)
        {
            u = move.fc, v = move.tc, same = move.fr;
            if (u > v)
                swap(u, v);
            for (int i = u + 1; i < v; i++)
            {
                if (chess.grid[same][i].type != Piecetype::None)
                    return false;
            }
        }
        else
        {
            if (u > v)
                swap(u, v);
            for (int i = u + 1; i < v; i++)
            {
                if (chess.grid[i][same].type != Piecetype::None)
                    return false;
            }
        }
    }
    break;

    case Piecetype::Bishop:
    {
        if (abs(move.fr - move.tr) != abs(move.fc - move.tc))
            return false;
        int x = 1, y = 1;
        if (move.tc < move.fc)
            x = -1;
        if (move.tr < move.fr)
            y = -1;
        for (int i = move.fr + y, j = move.fc + x; i != move.tr; i += y, j += x)
        {
            if (chess.grid[i][j].type != Piecetype::None)
                return false;
        }
    }
    break;

    case Piecetype::Knight:
    {
        if (abs(move.fr - move.tr) == 2)
        {
            if (abs(move.fc - move.tc) != 1)
                return false;
        }
        else if (abs(move.fc - move.tc) == 2)
        {
            if (abs(move.fr - move.tr) != 1)
                return false;
        }
        else
            return false;
    }
    break;

    case Piecetype::Queen:
    {
        if (move.fr == move.tr || move.fc == move.tc)
        {
            int u = move.fr, v = move.tr, same = move.fc;
            if (move.fr == move.tr)
            {
                u = move.fc, v = move.tc, same = move.fr;
                if (u > v)
                    swap(u, v);
                for (int i = u + 1; i < v; i++)
                {
                    if (chess.grid[same][i].type != Piecetype::None)
                        return false;
                }
            }
            else
            {
                if (u > v)
                    swap(u, v);
                for (int i = u + 1; i < v; i++)
                {
                    if (chess.grid[i][same].type != Piecetype::None)
                        return false;
                }
            }
        }
        else if (abs(move.fr - move.tr) == abs(move.fc - move.tc))
        {
            int x = 1, y = 1;
            if (move.tc < move.fc)
                x = -1;
            if (move.tr < move.fr)
                y = -1;
            for (int i = move.fr + y, j = move.fc + x; i != move.tr; i += y, j += x)
            {
                if (chess.grid[i][j].type != Piecetype::None)
                    return false;
            }
        }
        else
            return false;
    }
    break;

    case Piecetype::King:
    {
        if (abs(move.fr - move.tr) > 1 || abs(move.fc - move.tc) > 1)
            return false;
    }
    break;
    }
    return true;
}
