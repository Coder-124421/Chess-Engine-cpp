// #include "board.h"
// #include "piece.h"
// #include "check_detector.h"
// #include "move_detector.h"
// #include "move.h"
// #include "validity.h"
// #include <iostream>
// using namespace std;
// int main()
// {
//     Board chess;
//     chess.reset();
//     chess.show();
//     int turn = 1; // implies that it is white's turn;
//     while (true)
//     {
//         COLOR side = (turn) ? COLOR::White : COLOR::Black;
//         bool isCheck = (CheckDetector::check(chess, side));
//         if (!MoveDetector::Moveexist(chess, side))
//         {
//             if (!isCheck)
//             {
//                 cout << "STALEMATE!\n THE GAME ENDS IN A DRAW";
//             }
//             else
//             {
//                 cout << "CHECKMATE!\n";
//                 if (turn)
//                     cout << "BLACK WINS\n";
//                 else
//                     cout << "WHITE WINS\n";
//                 break;
//             }
//         }
//         if (side == COLOR::White)
//             cout << "White to move\n";
//         else
//             cout << "Black to move\n";
//         string s, t;
//         cin >> s;
//         if (s == "call")
//             break;
//         if (s == "resign")
//         {
//             cin >> t;
//             string p = (t == "white") ? "black" : "white";
//             cout << t << " resigned, " << p << " won by resignation\n";
//             break;
//         }
//         else if (s == "draw")
//         {
//             if (turn)
//                 cout << "white offers a draw \n";
//             else
//                 cout << "black offers a draw\n";
//             cout << "yes/no\n";
//             cin >> t;
//             if (t == "yes")
//             {
//                 cout << "The game is a draw\n";
//                 break;
//             }
//             else
//             {
//                 chess.show();
//                 continue;
//             }
//         }
//         cin >> t;
//         Move move = MoveManager::tomove(s, t);
//         if (Validator::isLegalMove(chess, move, side))
//         {
//             piece toundo = MoveManager::MakeMove(chess, move);
//             if (CheckDetector::check(chess, side))
//             {
//                 MoveManager::Undo(chess, move, toundo);
//                 cout << "Invalid Move\n";
//                 continue;
//             }
//             turn = 1 - turn;
//             chess.show();
//         }
//         else
//             cout << "Invalid Move\n";
//     }
// }
// this file is for running the chess engine on terminal instead of raylib
