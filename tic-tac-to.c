#include "tic-tac-to.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void resetBoard()
{
    // loop para deixar o tabuleiro limpo
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpaces()
{
    int freeSpaces = 9;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }

    return freeSpaces;
}

void playerMove()
{
    int row;
    int column;

    do
    {
        printf("Digite linha #(1-3): ");
        scanf("%d", &row);
        row--; // tabuleiro inicia na posição 0
        printf("Digite coluna #(1-3): ");
        scanf("%d", &column);
        column--; // tabuleiro inicia na posição 0

        if (board[row][column] != ' ') {
            printf("Movimento Invalido\n");
        }
        else {
            board[row][column] = PLAYER;
            break; 
        }
    } while (board[row][column] != ' ');
    
}

void computerMove()
{
    srand(time(0));
    int row;
    int column;

    if (checkFreeSpaces() > 0) {
        do
        {
            row    = rand() % 3;
            column = rand() % 3;

        } while (board[row][column] != ' ');
        
        board[row][column] = COMPUTER;
    }
    else {
        printWinner(' ');
    }
}

char checkWinner()
{
    // verifica linhas
    for (int i = 0; i < ROW; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }

    // verifica colunas
    for (int i = 0; i < ROW; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // verifica diagonais
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    // verifica diagonais
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }

    return ' ';

}

void printWinner(char winner)
{
    if (winner == PLAYER) {
        printf("VOCE VENCEU!!!\n");
    } else if (winner == COMPUTER) {
        printf("VOCE PERDEU!!!\n");
    } else {
        printf("EMPATE!!!\n");
    }
}