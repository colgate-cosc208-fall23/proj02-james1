/*****
 * Project 02: Grid game
 * COSC 208, Introduction to Computer Systems, Fall 2023
 * James Burke
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
bool makeMove(GameState *game, int col);
bool checkWinner(GameState *game, int row, int col);
void freeBoard(GameState *game);

int main() {
    GameState* game = initializeGame();
    printGame(game);
    int col;
    char input[10];

    while (true){
        printf("Player %c's turn\n", game->curPlayer);
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &col);

        if(col > COLS || col < 0){
        printf("Invalid input, try again!");
        }

        if(makeMove(game, col)){
            printGame(game);
            printf("Player %c wins! Play again?", game->curPlayer);
            break;
        }

        printGame(game);

        game->curPlayer = (game->curPlayer == 'X') ? 'O' : 'X';

    }
  
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


bool makeMove(GameState *game, int col){
    for(int i = ROWS-1; i >= 0; i--){
        if(game->board[i][col] == ' '){
            game->board[i][col] = game->curPlayer;
            game->moves+=1;
            return (checkWinner(game, i, col));
        }
    }
    printf("Column is full! Try again\n");
    return false;
}


bool checkWinner(GameState *game, int row, int col){
    int dir[4][2] = {{0,1}, {1,0}, {1,1}, {1,-1}};
    return false; 
}

/*
void freeBoard(GameState *game){
    
}
*/