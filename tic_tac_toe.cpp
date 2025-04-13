#include <iostream>
#include <vector>
using namespace std;
void initializeBoard(vector<char>& board){
    for(int i = 0; i<9; ++i){
        board[i] = ' ';
    }
}
void printboard(const vector<char>& board){
    cout << "\n Tic Tac Toe Board\n";
    for(int i=0; i < 9; ++i){
        cout << " " << board[i] << " ";
        if(i%3==2) cout <<"\n";
        else cout << "|";
    }
    cout << endl;
}
bool makeMove(vector<char>& board, int position, char player){
    if(position<1 || position >9 || board[position-1] !=' '){
        cout << "Invalid move! Try Again.\n";
        return false;
    }
    board[position-1] = player;
    return true;
}
int main(){
    vector<char> board(9);
    initializeBoard(board);
    char player = 'X';
    int position;
    bool gameWon = false;
    while (!gameWon)
    {
        printboard(board);
        cout << " Player" << player << "Enter your move(1-9) ";
        cin >> position;
        if(makeMove(board,position,player)){
            gameWon;
        }
    }
    
    
}