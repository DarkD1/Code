#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
vector<vector<int> > chessBoard;
int n;

bool validPosition(int row, int col){
    for(int i = 0; i < col; i++)
        if(chessBoard[row][i])  return false;
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(chessBoard[i][j]) return false;
    for(int i = row, j = col; i < n && j >= 0; i++, j--)
        if(chessBoard[i][j]) return false;
    return true;
}
bool nQueen(int col = 0){
    if(col >= n)
        return true;
    for(int row = 0; row < n; row++){
        if(validPosition(row, col)){
            chessBoard[row][col] = 1;
            if(nQueen(col + 1)) return true;
            chessBoard[row][col] = 0;
        }
    }
    return false;
}
void printSolution(){
    for(vector<int> i: chessBoard){
        for(int j: i)   cout << j << " ";
        cout << endl;
    }
}
int main(){
    cout << "Enter the value of n: ";
    cin >> n;
    chessBoard = vector<vector<int > > (n , vector<int>(n, 0));
    if(n > 3 && nQueen())   printSolution();
    else cout << "Solution Doesn't Exist" << endl;
    return 0;
}

