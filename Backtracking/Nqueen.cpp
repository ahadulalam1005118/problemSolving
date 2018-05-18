//
// Created by ahad on 5/18/18.
//
#include<iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>Board, int row, int col) {

    for (int c = 0; c < col; c++)
        if (Board[row][c])
            return false;

    for (int r =row, c=col; r>=0 && c>=0; r--, c--)
        if (Board[r][c])
            return false;

    for (int r=row, c=col; c>=0 && r<Board[0].size(); r++, c--)
        if (Board[r][c])
            return false;

    return true;

}
void printBoard(vector<vector<int>> Board) {
    for(int i = 0; i< Board[0].size(); i++) {
        for(int j =0; j< Board[0].size(); j++) {
            cout << Board[i][j] << " ";
        }
        cout<< endl;
    }
}

bool NQueenSolve(vector<vector<int>>Board, int col ) {
    int maxSize = Board[0].size();
    if(col>=maxSize) {
        printBoard(Board);
        return true;
    }
    for(int i=0; i<maxSize; i++) {
        if(isSafe(Board, i, col)) {
            cout << i <<col << endl;
            Board[i][col] = 1;
            if(NQueenSolve(Board,col+1)) {
                return true;                       //jodi true return kore... need to check
            }
            Board[i][col] = 0;

        }

    }
    return false; // false return korle ager stage e chole jabe... matha gulay ektu

}


int main() {
    vector<vector<int>> input {{0,0,0,0},
                               {0,0,0,0},
                               {0,0,0,0},
                               {0,0,0,0}};
    if(NQueenSolve(input,0)) {
        cout << "y";
    }
}

