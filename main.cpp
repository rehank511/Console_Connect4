//
//  main.cpp
//  Project 5
//
//  Created by Rehan Kedia on 12/4/17.
//  Copyright © 2017 Rehan Kedia. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class connect {
public:
    char board[6][7];
    
    void printBoard() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                cout << ":" << board[i][j];
            }
            cout << ";" << endl;
        }
        cout << "______________" << endl;
        cout << "0 1 2 3 4 5 6 " << endl;
    }
    bool checkMove(int colm)
    {
        if (colm < 0 || colm > 6) {
            return false;
        }
        else
            for (int i = 0; i < 6; i++) {
                if (board[i][colm] == 'X' || board[i][colm] == 'O') {
                    system("cls");
                    printBoard();
                    cout << " Full colmumn choose another one.." << endl;
                    cin >> colm;
                    checkMove(colm);
                }
                return true;
            }
    }
    void makeMove(char player, int colm) {
        if (colm >= 0 && colm <= 6) {
            if (board[0][colm] == ' ') {
                int i;
                for (i = 0; board[i][colm] == ' '; i++) {
                    if (i == 5) {
                        board[i][colm] = player;
                        return;
                    }
                }
                i--;
                board[i][colm] = player;
                return;
            }
            else {
                return;
            }
        }
    }
    bool isFull() {
        int full = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (board[i][j] != ' ') {
                    full++;
                }
            }
        }
        if (full == 42) {
            return true;
        }
        else
            return false;
    }
    bool hasWon(char player) {
        
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                    system("cls");
                    printBoard();
                    cout << "Gamer " << player << " won!!!" << endl;
                    return false;
                }
                
            }
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (board[i][j] != ' '&& board[i][j] == board[i + 1][j] && board[i][j] == board[1 + 2][j] && board[i][j] == board[i + 3][j]) {
                    system("cls");
                    printBoard();
                    cout << "Gamer " << player << " won!!!" << endl;
                    return false;
                }
                
            }
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (board[i][j] != ' '&& board[i][j] == board[i + 1][j+1] && board[i][j] == board[1 + 2][j] && board[i][j+2] == board[i + 3][j+3]) {
                    system("cls");
                    printBoard();
                    cout << "Gamer " << player << " won!!!" << endl;
                    return false;
                }
                
            }
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (board[i][j] != ' '&& board[i][j] == board[i + 1][j-1] && board[i][j] == board[1 + 2][j-2] && board[i][j] == board[i + 3][j-3]) {
                    system("cls");
                    printBoard();
                    cout << "Gamer " << player << " won!!!" << endl;
                    return false;
                }
                
            }
        }
        
        return true;
    }
};
int main()
{
    connect a;
    int colm;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            a.board[i][j] = ' ';
        }
    }
    a.printBoard();
    char player = 'X';
    while (int x = 1) {
        if (player == 'X') {
            cout << "First player make a move." << endl;
            cin >> colm;
            a.makeMove(player, colm);
            while (a.checkMove(colm) == false) {
                cout << "Incorrect colmumn... \n Choose a new colmumn..." << endl;
                cin >> colm;
            }
            if (a.hasWon(player) == false) {
                system("pause");
                return 0;
            }
            player = 'O';
        }
        else if (player == 'O') {
            cout << " Second player make a move." << endl;
            cin >> colm;
            a.makeMove(player, colm);
            while (a.checkMove(colm) == false) {
                cout << "Incorrect colmumn... \n Choose a new colmumn..." << endl;
                cin >> colm;
            }
            if (a.hasWon(player) == false) {
                system("pause");
                return 0;
            }
            player = 'X';
        }
        if (a.isFull() == true) {
            system("cls");
            cout << "All options are filled. No one wins the game" << endl;
            a.printBoard();
        }
        system("cls");
        a.printBoard();
    }
    return 0;
}
