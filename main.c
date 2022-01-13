#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// variáveis global
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);


int main()
{
    char winner = ' ';


    resetBoard();
    printBoard();
    

    return 0;
}

void resetBoard()
{
    // loop para deixar o tabuleiro limpo
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{

}

int checkFreeSpaces()
{

}

void playerMove()
{

}

void computerMove()
{

}

char checkWinner()
{

}

void printWinner(char winnner)
{

}