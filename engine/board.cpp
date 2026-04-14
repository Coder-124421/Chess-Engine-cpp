#include "board.h"
#include "move.h"
#include<iostream>
#include <vector>
using namespace std;

Board :: Board(){
     grid =  vector<vector<piece>>(8, vector<piece>(8));
     reset();
}
 void Board :: reset(){
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) grid[i][j]= piece();
    for(int i=0;i<8;i++){
        grid[1][i] = piece(COLOR::Black, Piecetype::Pawn);
        grid[6][i] = piece(COLOR::White, Piecetype::Pawn);
    }
    grid[0][0] = grid[0][7]  = piece(COLOR:: Black, Piecetype:: Rook);
    grid[0][1] = grid[0][6]  = piece(COLOR:: Black, Piecetype:: Knight);
    grid[0][2] = grid[0][5]  = piece(COLOR:: Black, Piecetype:: Bishop);
    grid[0][3] = piece(COLOR:: Black, Piecetype:: Queen);
    grid[0][4] = piece(COLOR:: Black, Piecetype:: King);
    grid[7][0] = grid[7][7]  = piece(COLOR:: White, Piecetype:: Rook);
    grid[7][1] = grid[7][6]  = piece(COLOR:: White, Piecetype:: Knight);
    grid[7][2] = grid[7][5]  = piece(COLOR:: White, Piecetype:: Bishop);
    grid[7][3] = piece(COLOR:: White, Piecetype:: Queen);
    grid[7][4] = piece(COLOR:: White, Piecetype:: King);
 }
// This was made for the teminal access
//  void Board:: show(){
//     cout<<"   -";
//     for(int i=0;i<8;i++) cout<<"--";
//     cout<<"\n";
//     for(int i=0;i<8;i++){
//         cout<<8-i<<" | ";
//         for(int j=0;j<8;j++){
//             cout<<tochar(grid[i][j])<<' ';
//         }
//         cout<<"|\n";
//     }
//     cout<<"   -";
//     for(int i=0;i<8;i++) cout<<"--";cout<<'\n';
//     cout<<"    a b c d e f g h\n";
//     cout<<"\n";
//  }
 
  