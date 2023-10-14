/*****
 * Project 02: Grid game
 * COSC 208, Introduction to Computer Systems, Fall 2023
 *****/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 7

typedef struct{
    char **board;
    char curPlayer;
    int moves;
} GameState;

GameState* initializeGame();
void printGame(GameState *game);
void makeMove(GameState *game, int col);
bool checkWinner(GameState *game, int row, int col);
void freeBoard(GameState *game);

int main() {
    GameState* game = initializeGame();
    printGame(game);
  
}

GameState* initializeGame(){
    GameState *game = malloc(sizeof(GameState));
    game->board = malloc(sizeof(char *) * ROWS);
    for(int i = 0; i < ROWS; i++){
        game->board[i] = malloc(sizeof(char) * COLS);
        for(int j = 0; j < COLS; j++){
            game->board[i][j] = ' ';
        }
    }
    game->curPlayer = 'X';
    game->moves = 0;
    return game;
}

void printGame(GameState *game){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            printf("|%c", game->board[i][j]);
        }
        printf("|\n");
    }
}


void makeMove(GameState *game, int col){
    for(int i = ROWS-1; i >= 0; i--){
        if(game->board[i][col] == ' '){
            game->board[i][col] = game->curPlayer;
            game->moves+=1;
        }
    }
    printf("Column is full! Try again");
}

bool checkWinner(GameState *game, int row, int col){
    
}

void freeBoard(GameState *game){
    
}
