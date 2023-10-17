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
    bool play = true;

    while (play){
        printf("Player %c's turn. Moves: %d\n", game->curPlayer, game->moves);
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &col);

        if(col > COLS || col < 0){
            printf("Invalid input, try again!");
            continue;
        }

        if(makeMove(game, col)){
            printGame(game);
            printf("Player %c wins! Play again?\n", game->curPlayer);
            play = false;
        }

        printGame(game);

        game->curPlayer = (game->curPlayer == 'X') ? 'O' : 'X';

    }

    freeBoard(game->board);
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
    char piece = game->curPlayer;
    for(int i = 0; i < 4; i++){
        int ct = 1;
        //using -1 and 1 to check left and right adjancency was inspired by OpenAI's ChatGPT (licensing agreement provided at end of code)
        for(int j = -1; j <= 1; j+=2){
            int dirX = dir[i][0] * j;
            int dirY = dir[i][1] * j;
        
            int newRow = row + dirX;
            int newCol = col + dirY;

            printf("dirX = %d, dirY = %d \n", dirX, dirY);
            printf("newRow = %d, newCol = %d \n", newRow, newCol);
            while(newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && (game->board[newRow][newCol] == piece)){
                ct++;
                if(ct == 4){
                    return true;
                }
                newRow += dirX;
                newCol += dirY;
            }
        }
    }
    return false;
}

void freeBoard(GameState *game){
    for(int i = 0; i < ROWS; i++){
        free(game->board[i]);
    }
    free(game->board);
    free(game);
}

/* via OpenAI:
The code provided by me (or any other OpenAI model) is generated on-the-fly and is not copyrighted or 
sourced from any specific external location. You're free to use, modify, and distribute the code as you see fit.
Licensing Requirements:
There are no specific licensing requirements for the code. 
You can consider it as being under a permissive license, like the MIT License or similar, 
which means you can use it for any purpose without any restrictions, and you're not 
required to include the original copyright notice or disclaimers.
*/