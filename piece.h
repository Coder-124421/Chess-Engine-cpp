#pragma once
enum class COLOR
{
     White,
     Black,
     None
};
enum class Piecetype
{
     King,
     Queen,
     Bishop,
     Knight,
     Rook,
     Pawn,
     None
};

struct piece
{
     COLOR color;
     Piecetype type;

public:
     piece() : color(COLOR::None), type(Piecetype::None) {}
     piece(COLOR c, Piecetype t) : color(c), type(t) {}
};
char tochar(piece A);
