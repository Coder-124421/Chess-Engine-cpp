#pragma once
enum class Color
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
     Color color;
     Piecetype type;

public:
     piece() : color(Color::None), type(Piecetype::None) {}
     piece(Color c, Piecetype t) : color(c), type(t) {}
};
char tochar(piece A);
