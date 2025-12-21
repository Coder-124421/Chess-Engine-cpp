
class Board;
struct Move;
enum class Color;
class Validator
{
public:
  static bool isLegalMove(Board &chess, Move move, Color side);
};
