#include "raylib.h"
#include "move.h"
#include "board.h"
#include "piece.h"
#include "move_detector.h"
#include "check_detector.h"
#include "validity.h"
#include <map>
#include <cmath>
using namespace std;
map<pair<COLOR, Piecetype>, Texture2D> textures;

void LoadPieceTextures()
{
    textures[{COLOR::White, Piecetype::Pawn}] = LoadTexture("assets/pieces/wp.png");
    textures[{COLOR::White, Piecetype::Rook}] = LoadTexture("assets/pieces/wr.png");
    textures[{COLOR::White, Piecetype::Knight}] = LoadTexture("assets/pieces/wn.png");
    textures[{COLOR::White, Piecetype::Bishop}] = LoadTexture("assets/pieces/wb.png");
    textures[{COLOR::White, Piecetype::Queen}] = LoadTexture("assets/pieces/wq.png");
    textures[{COLOR::White, Piecetype::King}] = LoadTexture("assets/pieces/wk.png");

    textures[{COLOR::Black, Piecetype::Pawn}] = LoadTexture("assets/pieces/bp.png");
    textures[{COLOR::Black, Piecetype::Rook}] = LoadTexture("assets/pieces/br.png");
    textures[{COLOR::Black, Piecetype::Knight}] = LoadTexture("assets/pieces/bn.png");
    textures[{COLOR::Black, Piecetype::Bishop}] = LoadTexture("assets/pieces/bb.png");
    textures[{COLOR::Black, Piecetype::Queen}] = LoadTexture("assets/pieces/bq.png");
    textures[{COLOR::Black, Piecetype::King}] = LoadTexture("assets/pieces/bk.png");
}
void DrawPieces(Board &board, int TILE)
{
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            piece p = board.grid[r][c];
            if (p.type == Piecetype::None)
                continue;

            Texture2D tex = textures[{p.color, p.type}];

            DrawTexturePro(
                tex,
                {0, 0, (float)tex.width, (float)tex.height},
                {(float)c * TILE, (float)r * TILE, (float)TILE, (float)TILE},
                {0, 0},
                0,
                WHITE);
        }
    }
}
int main()
{
    vector<bool>right(9,false);
    bool gameOver = false;
    COLOR winner = COLOR::None;
    InitWindow(600, 650, "Chess GUI");
    SetTargetFPS(60);
    bool delay = false;
    const int tile = 75;
    Board board;
    board.reset();
    LoadPieceTextures();
    bool selected = false;
    int sr = -1, sc = -1;
    COLOR side = COLOR::White;
    double got;
    while (!WindowShouldClose())
    {
        bool isCheck = false;
        COLOR opp = COLOR::White;
        if (side == COLOR::White)
            opp = COLOR::Black;

        if (gameOver && !delay)
        {
            if (GetTime() - got >= 2.0)
            {
                delay = true;
            }
        }
        BeginDrawing();
        if (delay)
        {
            DrawRectangle(0, 0, 600, 600, Fade(BLACK, 0.7f));
            if (winner != COLOR::None)
                DrawText("CHECKMATE", 160, 240, 50, RED);
            else
                DrawText("STALEMATE", 160, 240, 50, RED);
            // Winner text
            if (winner == COLOR::White)
                DrawText("White Wins", 210, 310, 30, WHITE);
            else if (winner == COLOR::Black)
                DrawText("Black Wins", 210, 310, 30, WHITE);
            else
                DrawText("Draw", 210, 310, 30, WHITE);
        }
        else
        {
          if(!gameOver)  DrawText(side == COLOR::White ? "White to move" : "Black to move", 200, 610, 30, BLACK);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Vector2 mouse = GetMousePosition();
                int r = mouse.y / tile;
                int c = mouse.x / tile;

                if (r >= 0 && r < 8 && c >= 0 && c < 8)
                {
                    if (!selected)
                    {
                        if (board.grid[r][c].type != Piecetype::None &&
                            board.grid[r][c].color == side)
                        {
                            sr = r;
                            sc = c;
                            selected = true;
                        }
                    }
                    else
                    {
                        Move move{sr, sc, r, c};
                        if(board.grid[sr][sc].type==Piecetype::King && board.grid[sr][sc].color==side && (sr == r && abs(sc-c)==2)){
                            bool kingside = true;
                            if(c<sc) kingside = false;
                           Validator::castle(board,side,kingside,right);
                        }
                       else if (Validator::isLegalMove(board, move, side))
                        {
                            int y = 0;
                            if(side==COLOR::Black) y+=4;
                           
                            piece toundo = MoveManager::MakeMove(board, move);
                            isCheck = (CheckDetector::check(board, side));
                            if (isCheck)
                            {
                                MoveManager::Undo(board, move, toundo);
                            }
                            else
                            {
                                if(board.grid[move.fr][move.fc].type==Piecetype::King){
                              right[y]= true;
                              right[y<<1] = true;
                           }
                           else if(board.grid[move.fr][move.fc].type==Piecetype::Rook){
                               if(side==COLOR::White){
                                 if(move.fr==7){
                                    if(move.fc==0) right[y<<1]=true;
                                    else if(move.fc==7) right[y]= true;
                                 }
                               }
                               else {
                                if(move.fr==0){
                                     if(move.fc==0) right[y<<1]=true;
                                    else if(move.fc==7)right[y]= true;
                                }
                               }
                           }
                                side = opp;
                                isCheck = (CheckDetector::check(board, side));
                                if (!MoveDetector::Moveexist(board, side))
                                {
                                    gameOver = true;
                                    got = GetTime();
                                    if(isCheck) {
                                    if (side == COLOR::White)
                                        winner = COLOR::Black;
                                    else 
                                        winner = COLOR::White;}
                                }
                            }
                        }
                        selected = false;
                    }
                }
            }
            ClearBackground(RAYWHITE);
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    Color color = ((i + j) & 1) ? BROWN : BEIGE;
                    DrawRectangle(i * tile, j * tile, tile, tile, color);
                }
            }
            DrawPieces(board, tile);
            if (selected)
                DrawRectangleLines(sc * tile, sr * tile, tile, tile, BLUE);
                isCheck = CheckDetector::check(board, side);
            if (isCheck)
            {
                float pulse = (std::sin(GetTime() * 5) + 1) * (0.5f);
                Color pulseRed = Fade(RED, 0.3f + 0.4f * pulse);

                pair<int, int> kpos = CheckDetector::KingPos(board, side);
                DrawRectangle(
                    kpos.second * tile,
                    kpos.first * tile,
                    tile, tile,
                    pulseRed);
            }
        }
        EndDrawing();
    }
    for (auto &t : textures)
        UnloadTexture(t.second);
    CloseWindow();
}
