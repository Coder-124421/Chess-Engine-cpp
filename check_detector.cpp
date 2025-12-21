#include "board.h"
#include "check_detector.h"
#include <bits/stdc++.h>
using namespace std;
bool CheckDetector::check( Board& chess, Color side){
    Color opp = Color::White;
    if(side== Color:: White) opp = Color::Black;
    int kr=-1, kc=-1;
     for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(chess.grid[i][j].type == Piecetype:: King && chess.grid[i][j].color == side){
                    kr = i, kc = j; break; // there is definitely not more than one king;
            }
        }
        if(kr!=-1) break;
     }
     // straight lines first 
     for(int i= kr+1;i<8 ;i++){
        piece cur = chess.grid[i][kc];
        if(cur.type!= Piecetype:: None){
            if( cur.color == opp && (cur.type== Piecetype:: Rook || cur.type == Piecetype::Queen)) return true;
            break;
        }
     }
     for(int i= kr-1;i>=0 ;i--){
        piece cur = chess.grid[i][kc];
        if(cur.type!= Piecetype:: None){
            if( cur.color == opp && (cur.type== Piecetype:: Rook || cur.type == Piecetype::Queen)) return true;
            break;
        }
     }
     for(int i= kc+1;i<8 ;i++){
        piece cur = chess.grid[kr][i];
        if(cur.type!= Piecetype:: None){
            if( cur.color == opp && (cur.type== Piecetype:: Rook || cur.type == Piecetype::Queen)) return true;
            break;
        }
     }
     for(int i= kc-1;i>=0 ;i--){
        piece cur = chess.grid[kr][i];
        if(cur.type!= Piecetype:: None){
            if( cur.color == opp && (cur.type== Piecetype:: Rook || cur.type == Piecetype::Queen)) return true;
            break;
        }
     }
     vector<pair<int,int>>dir = {{1,1},{1,-1},{-1,1},{-1,-1}};
     vector<int>kingatt = {1,-1,0};
     for(auto i:kingatt){
        for(auto j:kingatt){
            if(i==j&& i==0) continue;
            int i1 = kr+i;
            int j1 = kc+j;
            if(i1>=0 && i1<8 && j1>=0 && j1<8){
               piece cur = chess.grid[i1][j1];
               if(cur.type==Piecetype:: King && cur.color == opp) return true;
            }
        }
     }
     vector<pair<int,int>>knight = {{1,2},{2,1}};
     for(auto [dx,dy]:dir){
         // checking diagonals 
        for(int i= kr+dx,j= kc+dy;i<8 && i>=0 && j<8 && j>=0 ; j+=dy,i+=dx){
            piece cur = chess.grid[i][j];
            if(cur.type!=Piecetype::None){
                if(cur.color == opp ){
                     if(cur.type== Piecetype:: Bishop || cur.type == Piecetype::Queen) return true;
                     else if(cur.type== Piecetype:: Pawn && abs(kr-i)==1){
                        if(cur.color == Color::White){
                            if(i>kr) return true;
                        }
                        else if(i<kr) return true;
                     }
                }
            break;
            }
        }
        for(auto [i,j]:knight){
            if(kr+i*dx >=0 && kr+i*dx <8 && kc+j*dy>=0 && kc+j*dy<8) {
                 piece cur = chess.grid[kr+i*dx][kc+j*dy];
            if(cur.color== opp && cur.type == Piecetype::Knight) return true;
            }
        }
     }
     return false;
 }