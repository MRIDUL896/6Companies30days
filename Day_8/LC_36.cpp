//36. Valid Sudoku
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> set;
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                if(set.find(board[i][j]) != set.end()) return false;
                set.insert(board[i][j]);
            }
        }

        for(int i=0;i<9;i++){
            unordered_set<char> set;
            for(int j=0;j<9;j++){
                if(board[j][i] == '.') continue;
                if(set.find(board[j][i]) != set.end()) return false;
                set.insert(board[j][i]);
            }
        }

        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                unordered_set<char> set;
                for(int row=i;row<=i+2;row++){
                    for(int col=j;col<=j+2;col++){
                        if(board[row][col] == '.') continue;
                        if(set.find(board[row][col]) != set.end()) return false;
                        set.insert(board[row][col]);
                    }
                }
            }
        }

        return true;
    }
};