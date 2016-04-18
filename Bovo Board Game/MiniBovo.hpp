#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
//#include <windows.h>
//for linux #include <unistd.h> and call sleep(1);
#include <unistd.h> 
using namespace std;

#define SIZE 22

//structure to represent board position,needs validation

struct Position {
    int x;
    int y;
    Position(); //no-arg constructor
    Position(int x, int y); //initialize coordinates
    bool operator==(const Position& p); //compare two positions
};

//structure to represent the board

class Board {
    //a 6X6 matrix to represent the board grid
    char grid[SIZE][SIZE];

    //last played position
    Position lastPosition;

public:
    //no-arg constructor for Board
    Board();
    //return a copy of lastPosition
    Position getLastPosition();
    //set a piece on the board to a given symbol
    void setPiece(const int& x, const int& y, const char& c);
    //return the symbol at a particular x and y coordinate
    char getPiece(const int& x, const int& y);
};
//check if position is on board
bool onBoard(const Position& p);


//create function pointer type for play strategies
typedef void (*fp) (char symbol, Board& board);
//basic play strategy that relies on random play.
void playRandomStrategy(char symbol, Board& board);
//strategy that plays at the first unoccupied neighbour position.
void playClockWiseStrategy(char symbol, Board& board);

//class to represent 1 player in the game

class Player {
    char symbol; //the symbol this player will use.
    fp strategy; //the strategy this player will use.
public:
    Player(char symbol);
    Player(char symbol, fp strategy);
    //make a move based on a strategy.
    void play(Board& board);
};

class MiniBovo {
    //game board
    Board board;
    //if noughtsTurn is true it is player 0's turn to play, otherwise it is player X's turn
    bool noughtsTurn;
    //Players O and X;
    Player playerO;
    Player playerX;

    //if at least 1 move has been made, began is true, otherwise it is false
    bool began;

    //@TODO: include marked positions counter.

public:

    //no-arg constructor for MiniBovo 
    MiniBovo();

    //constructor for MiniBovo influencing which player should go first
    MiniBovo(bool noughtsTurn);

    //constructor for MiniBovo controlling player order and settings
    MiniBovo(bool noughtsTurn, fp oStrategy, fp xStrategy);


    //display the board as a 6X6 matrix
    void displayBoard();

    //the method start() is used to start the game
    void start();

    //play() makes 1 move in the game
    void play();

    //complete() checks to see if the game is over
    bool complete();

    //boardFull() checks to see if every cell in the board either has a 0 or an X
    bool boardFull();

    //winner returns 'X' if X is the winner, 'O' if O is the winner and 'N' if a winner has not been found
    char winner();

};

