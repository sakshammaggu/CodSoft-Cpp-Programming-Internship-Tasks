#include <iostream>
#include <vector>
using namespace std;

// function that will print the board pattern
void printBoard(const vector<vector<char>>& board) 
{
    for (const auto& row : board) 
    {
        for (char cell : row) 
        {
            cout << cell << " | ";
        }
        cout << "\n---------\n";
    }
}

// functiont that will return who is winning
bool checkWin(const vector<vector<char>>& board, char player) 
{
    for (const auto& row : board) 
    {
        if (row[0] == player && row[1] == player && row[2] == player) 
        {
            return true;
        }
    }

    for (int col = 0; col < 3; ++col) 
    {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) 
        {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) 
    {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) 
    {
        return true;
    }

    return false;
}

// function that will check draw
bool checkDraw(const vector<vector<char>>& board) 
{
    for (const auto& row : board) 
    {
        for (char cell : row) 
        {
            if (cell == ' ') 
            {
                return false;
            }
        }
    }
    return true;
}

int main() 
{
    vector<vector<char>> board(3, vector<char>(3, ' '));
    vector<char> players = {'X', 'O'};
    int currentPlayer = 0;

    while (true) 
    {
        cout << "TIC-TAC-TOE GAME\n";
        printBoard(board);

        char playerSymbol = players[currentPlayer];
        int row, col;
        cout << "Player " << playerSymbol << ", enter your move (row column): ";
        cin >> row >> col;

        if (row>=0 && row<3 && col>=0 && col<3 && board[row][col]==' ') 
        {
            board[row][col] = playerSymbol;

            if (checkWin(board, playerSymbol)) 
            {
                printBoard(board);
                cout << "Player " << playerSymbol << " wins!\n";
                break;
            } 
            else if (checkDraw(board)) 
            {
                printBoard(board);
                cout << "It's a draw!\n";
                break;
            } 
            else 
            {
                currentPlayer = 1 - currentPlayer;
            }
        } 
        else 
        {
            cout << "Invalid move. Try again.\n";
        }
    }

    return 0;
}