/*****
 * Project 02: Grid game
 * COSC 208, Introduction to Computer Systems, Fall 2023
 *****/

#include <stdio.h>

// game.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 7

typedef struct {
    char **board;
    char currentPlayer;
    int moves;
} GameState;

GameState* initializeGame();
void printGame(GameState *game);
bool makeMove(GameState *game, int col);
bool checkWinner(GameState *game, int row, int col);
void freeBoard(GameState *game);

int main() {
  
}

GameState* initializeGame() {
    GameState *game = malloc(sizeof(GameState));
    game->board = malloc(sizeof (char *))
    
}

void printGame(GameState *game) {
   
}

bool makeMove(GameState *game, int col) {
    
}

bool checkWinner(GameState *game, int row, int col) {
    
}

void freeBoard(GameState *game) {
    
}
