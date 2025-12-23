#include "board.h"
#include "validity.h"
#include "check_detector.h"
#include "piece.h"
#include "move.h"
#include <bits/stdc++.h>
using namespace std;
void Validator:: castle(Board& board, COLOR &side,bool kingside, vector<bool>&state){
    int r= (side==COLOR::White)? 7:0;
    int c = 4;
    pair<int,int>kpos = CheckDetector::KingPos(board,side);
    if(kpos.first!=r) return ;
    if(kpos.second!=c) return ;
    if(CheckDetector::check(board,side)) return ;
    int y = 0;
    if(side==COLOR::Black) y+=4;
    if(!kingside) y<<=1;
    if(state[y]) return ;
    int x = -1;
    if(kingside) x=1;
    if(board.grid[r][c+x].type!=Piecetype::None) return ;
    if(board.grid[r][c+2*x].type!=Piecetype::None) return ;
    if(!kingside) if(board.grid[r][c+3*x].type!= Piecetype::None) return;
    board.grid[r][c+x] = board.grid[r][c];
    piece temp(COLOR::None, Piecetype::None);
    board.grid[r][c] = temp;
    if(CheckDetector::check(board,side)) {
        board.grid[r][c] = board.grid[r][c+x];
        board.grid[r][c+x] = temp;
        return ;
    }
    int l = 3;
    if(!kingside) l =-4;
    if(!(board.grid[r][c+l].type== Piecetype::Rook && board.grid[r][c+l].color==side)) return;
    board.grid[r][c+2*x] = board.grid[r][c+x];
    board.grid[r][c+x] = temp;
    if(CheckDetector::check(board,side)) {
        board.grid[r][c] = board.grid[r][c+2*x];;
        board.grid[r][c+2*x] = temp;
        return ;
    }
    board.grid[r][c+x]= board.grid[r][c+l];
    board.grid[r][c+l] = temp;
    state[y]= true;
    if(kingside) state[y<<1] = true;
    else state[y>>1] = true;
    side = (side==COLOR::White)? COLOR::Black:COLOR::White;
    return;
}
bool Validator::isLegalMove(Board &chess, Move move, COLOR side)
{
    if (move.fr < 0 || move.fr > 7 || move.fc < 0 || move.fc > 7 || move.tr < 0 || move.tr > 7 || move.tc < 0 || move.tc > 7)
         return false;

    COLOR opp = (side == COLOR::White) ? COLOR::Black : COLOR::White;
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
        if (((move.tr == move.fr - 1) && (side == COLOR::White)) || ((side == COLOR::Black) && (move.tr == move.fr + 1)))
        {
            if (move.tc == move.fc)
            {
                if (final.type != Piecetype::None)
                    return false;
            } // one square move;
            else if (abs(move.tc - move.fc) == 1)
            {
                if ((final.color == COLOR::None))
                    return false;
            }
            else
                return false;
        }
        else if (abs(move.tr - move.fr) == 2 && move.tc == move.fc)
        {
            if ((side == COLOR::White) && (!(move.fr == 6 && move.tr == move.fr - 2) || chess.grid[move.fr - 1][move.fc].type != Piecetype::None))
                return false;
            else if ((side == COLOR::Black) && (!(move.fr == 1 && move.tr == move.fr + 2) || chess.grid[move.fr + 1][move.fc].type != Piecetype::None))
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
        if (abs(move.fr - move.tr) > 1 || abs(move.fc - move.tc) > 2)
            return false;
            if(move.fr==move.tr && abs(move.fc - move.tc)==2){
                
            }
    }
    break;
    }
    return true;
}
