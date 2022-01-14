#ifndef TICTACTO_H
#define TICTACTO_H

// variáveis global
char board[3][3];
const char PLAYER   = 'X';
const char COMPUTER = 'O';
const int  ROW      = 3;
const int  COLUMN   = 3;

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

#endif