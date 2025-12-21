#include "piece.h"

char tochar(piece A)
{
    char c = '.';
    switch (A.type)
    {
    case Piecetype::King:
        c = 'K';
        break;
    case Piecetype::Queen:
        c = 'Q';
        break;
    case Piecetype::Bishop:
        c = 'B';
        break;
    case Piecetype::Knight:
        c = 'N';
        break;
    case Piecetype::Rook:
        c = 'R';
        break;
    case Piecetype::Pawn:
        c = 'P';
        break;
    default:
        c = '.';
    }
    return (A.color == Color::Black) ? c + 'a' - 'A' : c;
}