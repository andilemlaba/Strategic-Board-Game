#include "MiniBovo.hpp"

//No-arg constructor to create default position object.

Position::Position() : x(SIZE / 2), y(SIZE / 2) {
}

//Constructor with specified position. @TODO:Validation needed.

Position::Position(int xp, int yp) : x(xp), y(yp) {
}

//compare two positions for equality

bool Position::operator==(const Position& p) {
    return this->x == p.x && this->y == p.y;
}

//check if position is on board

bool onBoard(const Position& p) {
    if (p.x < 0 || p.x >= SIZE || p.y < 0 || p.y >= SIZE)
        return false;
    return true;
}

bool playAttackOrDefence(char symbol, Board& board, bool attack) {
    char opponent_symbol;
    if (!attack){
        if (symbol == 'X') opponent_symbol = 'O';
        else opponent_symbol = 'X';
    }
    /* check forward 3 in a row*/
    for (int i = 0; i < SIZE; i++) {//for all rows
        for (int j = 0; j < SIZE - 2; j++) {//for all columns that can fit 3 symbol matches in a horizontal line
            if (!attack) {
                if ((board.getPiece(i, j) == opponent_symbol)&&(board.getPiece(i, j + 1) == opponent_symbol)&&(board.getPiece(i, j + 2) == ' ')) {
                    board.setPiece(i, j + 2, symbol);
                    return true;
                } else if ((board.getPiece(i, j) == ' ') && (board.getPiece(i, j + 1) == opponent_symbol)&& (board.getPiece(i, j + 2) == opponent_symbol)) {
                    board.setPiece(i, j, symbol);
                    return true;
                } else if ((board.getPiece(i, j) == opponent_symbol) && (board.getPiece(i, j + 1) == ' ')&& (board.getPiece(i, j + 2) == opponent_symbol)) {
                    board.setPiece(i, j + 1, symbol);
                    return true;
                }
            } else {
                if ((board.getPiece(i, j) == symbol)&&(board.getPiece(i, j + 1) == symbol)&&(board.getPiece(i, j + 2) == ' ')) {
                    board.setPiece(i, j + 2, symbol);
                    return true;
                } else if ((board.getPiece(i, j) == ' ') && (board.getPiece(i, j + 1) == symbol)&& (board.getPiece(i, j + 2) == symbol)) {
                    board.setPiece(i, j, symbol);
                    return true;
                } else if ((board.getPiece(i, j) == symbol) && (board.getPiece(i, j + 1) == ' ')&& (board.getPiece(i, j + 2) == symbol)) {
                    board.setPiece(i, j + 1, symbol);
                    return true;
                }
            }
        }
    }
    //cout << "no row\n";
    /* check forward 3 in a column*/
    for (int i = 0; i < SIZE; i++) {//for all columns
        for (int j = 0; j < SIZE - 2; j++) {//for all rows that can fit 3 symbol matches in a vertical line
            if (!attack) {
                if ((board.getPiece(j, i) == opponent_symbol)&&(board.getPiece(j + 1, i) == opponent_symbol)&&(board.getPiece(j + 2, i)) == ' ') {
                    board.setPiece(j + 2, i, symbol);
                    return true;
                } else if ((board.getPiece(j, i) == ' ') && (board.getPiece(j + 1, i) == opponent_symbol)&& (board.getPiece(j + 2, i) == opponent_symbol)) {
                    board.setPiece(j, i, symbol);
                    return true;
                } else if ((board.getPiece(j, i) == opponent_symbol) && (board.getPiece(j + 1, i) == ' ')&& (board.getPiece(j + 2, i) == opponent_symbol)) {
                    board.setPiece(j + 1, i, symbol);
                    return true;
                }
            } else {
                if ((board.getPiece(j, i) == symbol)&&(board.getPiece(j + 1, i) == symbol)&&(board.getPiece(j + 2, i)) == ' ') {
                    board.setPiece(j + 2, i, symbol);
                    return true;
                } else if ((board.getPiece(j, i) == ' ') && (board.getPiece(j + 1, i) == symbol)&& (board.getPiece(j + 2, i) == symbol)) {
                    board.setPiece(j, i, symbol);
                    return true;
                } else if ((board.getPiece(j, i) == symbol) && (board.getPiece(j + 1, i) == ' ')&& (board.getPiece(j + 2, i) == symbol)) {
                    board.setPiece(j + 1, i, symbol);
                    return true;
                }
            }
        }
    }
    //cout << "no col\n";
    /*check 3 in backslash diagonals */
    for (int i = 0; i < SIZE - 2; i++) {//for all rows that can fit 3 symbol matches in a backslash diagonal line.
        for (int j = 0; j < SIZE - 2; j++) {//for all columns that can fit 3 symbol matches in backslash diagonal line.
            if (!attack) {
                if ((board.getPiece(i, j) == opponent_symbol)&&(board.getPiece(i + 1, j + 1) == opponent_symbol)&&(board.getPiece(i + 2, j + 2)) == ' ') {
                    board.setPiece(i + 2, j + 2, symbol);
                    return true;
                } else if ((board.getPiece(i, j) == ' ') && (board.getPiece(i + 1, j + 1) == opponent_symbol)&& (board.getPiece(i + 2, j + 2) == opponent_symbol)) {
                    board.setPiece(i, j, symbol);
                    return true;
                } else if ((board.getPiece(i, j) == opponent_symbol) && (board.getPiece(i + 1, j + 1) == ' ')&& (board.getPiece(i + 2, j + 2) == opponent_symbol)) {
                    board.setPiece(i + 1, j + 1, symbol);
                    return true;
                }
            } else {
                if ((board.getPiece(i, j) == symbol)&&(board.getPiece(i + 1, j + 1) == symbol)&&(board.getPiece(i + 2, j + 2)) == ' ') {
                    board.setPiece(i + 2, j + 2, symbol);
                    return true;
                } else if ((board.getPiece(i, j) == ' ') && (board.getPiece(i + 1, j + 1) == symbol)&& (board.getPiece(i + 2, j + 2) == symbol)) {
                    board.setPiece(i, j, symbol);
                    return true;
                } else if ((board.getPiece(i, j) == symbol) && (board.getPiece(i + 1, j + 1) == ' ')&& (board.getPiece(i + 2, j + 2) == symbol)) {
                    board.setPiece(i + 1, j + 1, symbol);
                    return true;
                }
            }
        }
    }
    //cout << "no back\n";
    /*check 3 in a forwardslash diagonals*/
    for (int i = 2; i < SIZE; i++) {//for all rows that can fit 3 symbol matches in a forwardslash diagonal line.
        for (int j = 0; j < SIZE - 2; j++) {//for all columns that can fit 3 symbol matches in a forwardslash diagonal line.
            if (!attack) {
                if ((board.getPiece(i, j) == opponent_symbol)&&(board.getPiece(i - 1, j + 1) == opponent_symbol)&&(board.getPiece(i - 2, j + 2)) == ' ') {
                    board.setPiece(i - 2, j + 2, symbol);
                    return true;
                } else if ((board.getPiece(i, j) == ' ') && (board.getPiece(i - 1, j + 1) == opponent_symbol)&& (board.getPiece(i - 2, j + 2) == opponent_symbol)) {
                    board.setPiece(i, j, symbol);
                    return true;
                } else if ((board.getPiece(i, j) == opponent_symbol) && (board.getPiece(i - 1, j + 1) == ' ')&& (board.getPiece(i - 2, j + 2) == opponent_symbol)) {
                    board.setPiece(i - 1, j + 1, symbol);
                    return true;
                }
            } else {
                if ((board.getPiece(i, j) == symbol)&&(board.getPiece(i - 1, j + 1) == symbol)&&(board.getPiece(i - 2, j + 2)) == ' ') {
                    board.setPiece(i - 2, j + 2, symbol);
                    return true;
                } else if ((board.getPiece(i, j) == ' ') && (board.getPiece(i - 1, j + 1) == symbol)&& (board.getPiece(i - 2, j + 2) == symbol)) {
                    board.setPiece(i, j, symbol);
                    return true;
                } else if ((board.getPiece(i, j) == symbol) && (board.getPiece(i - 1, j + 1) == ' ')&& (board.getPiece(i - 2, j + 2) == symbol)) {
                    board.setPiece(i - 1, j + 1, symbol);
                    return true;
                }
            }

        }
    }
    //cout << "no forw\n";
    return false;
}

//My rule based strategy
void playAndilesStrategy(char symbol, Board& board) {
    //cout << "Playing Andile's Strategy" << endl;
    //flag move made
    bool move_made = playAttackOrDefence(symbol, board, true);
    //cout << (move_made ? "Win" : "No Win") << endl;
    if (!move_made) {
        move_made = playAttackOrDefence(symbol, board, false);
        //cout << (move_made ? "Blocked" : "Not Blocked") << endl;
    }
    if (!move_made) {
        playRandomStrategy(symbol, board);
    }
}

//Basic play strategy that relies on random play positions

void playRandomStrategy(char symbol, Board& board) {
    //Randomly determine next board position to play		
    int r = rand() % SIZE;
    int c = rand() % SIZE;
    while (board.getPiece(r, c) != ' ') {//Find alternative as long as we keep getting an occupied position.
        r = rand() % SIZE;
        c = rand() % SIZE;
    }
    board.setPiece(r, c, symbol); //Play by marking position with player's symbol.
    //board.lastPosition=Position(r,c);//Record the played position.
}

//strategy that plays at position of the first unoccupied neighbour of last played position.

void playClockWiseStrategy(char symbol, Board& board) {
    for (int d = 1; d < SIZE; d++) {
        int r = board.getLastPosition().x - d;
        int c = board.getLastPosition().y;
        for (int i = 0; i < d; i++) {//move right along row, stop at d
            if (!onBoard(Position(r, c))) {
                c++;
                continue;
            }
            if (board.getPiece(r, c) == ' ') {
                board.setPiece(r, c, symbol);
                //board.lastPosition=Position(r,c);
                return;
            }
            c++;
        }
        for (int i = 0; i < (d * 2); i++) {//move down column, stop at d
            if (!onBoard(Position(r, c))) {
                r++;
                continue;
            }
            if (board.getPiece(r, c) == ' ') {
                board.setPiece(r, c, symbol);
                //board.lastPosition=Position(r,c);
                return;
            }
            r++;
        }
        for (int i = 0; i < (d * 2); i++) {//move left along row, stop at -d
            if (!onBoard(Position(r, c))) {
                c--;
                continue;
            }
            if (board.getPiece(r, c) == ' ') {
                board.setPiece(r, c, symbol);
                //board.lastPosition=Position(r,c);
                return;
            }
            c--;
        }
        for (int i = 0; i < (d * 2 + 1); i++) {//move up along column, stop at -d
            if (!onBoard(Position(r, c))) {
                r--;
                continue;
            }
            if (board.getPiece(r, c) == ' ') {
                board.setPiece(r, c, symbol);
                //board.lastPosition=Position(r,c);
                return;
            }
            r--;
        }

    }
}

//Constructor specifying player's symbol.

Player::Player(char symbol) {
    this->symbol = symbol; //Remember this is a pointer.
}

//Constructor specifying player's symbol and strategy.

Player::Player(char symbol, fp strategy) {
    this->symbol = symbol;
    this->strategy = strategy;
}

//Get the game board and mark this player's position.

void Player::play(Board& board) {
    //Position lp=board.lastPosition;//record last position
    strategy(symbol, board); //perform strategy for this player.	
    //cout<<(lp.equal(board.lastPosition))<<endl;					
}

//no-arg constructor for Board

Board::Board() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            setPiece(i, j, ' '); //Inititalize board positions.
}

Position Board::getLastPosition() {
    return lastPosition;
}

//set a piece on the board to a given symbol

void Board::setPiece(const int& x, const int& y, const char& c) {
    grid[x][y] = c;
    lastPosition = Position(x, y);
}

//return the symbol at a particular x and y coordinate

char Board::getPiece(const int& x, const int& y) {
    return grid[x][y];
}

//MiniBovo no-arg constructor with default players.

MiniBovo::MiniBovo() : playerO(Player('O', playAndilesStrategy)), playerX(Player('X', playAndilesStrategy)) {
    //give player 0 the first move
    noughtsTurn = true;
}

//Constructor for MiniBovo influencing which player should go first.

MiniBovo::MiniBovo(bool noughtsTurn) : playerO(Player('O', playAndilesStrategy)), playerX(Player('X', playAndilesStrategy)) {
    this->noughtsTurn = ((noughtsTurn) ? true : false);
}

//Constructor for MiniBovo controlling player order and strategies.

MiniBovo::MiniBovo(bool noughtsTurn, fp oStrategy, fp xStrategy) : playerO(Player('O', oStrategy)), playerX(Player('X', xStrategy)) {

}

//display the board as a 6X6 matrix

void MiniBovo::displayBoard() {
    cout << "  -";
    for (int p = 0; p < (SIZE + ((SIZE - 2)*2) + 5); p++)
        cout << " ";
    cout << "-" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "|";
        for (int j = 0; j < SIZE; j++) {
            char piece = board.getPiece(i, j);
            /*Position dp(i,j);
            Position lp=board.getLastPosition();
            if(dp==lp)
                    cout<<"\x1b[31m";*///make console background white and foreground red
            cout << " " << ((piece == ' ') ? string("  |") : piece + string(" |"));
            //cout<<"\x1b[0m";//reset console colors
        }
        cout << endl;
    }
    cout << "  -";
    for (int p = 0; p < (SIZE + ((SIZE - 2)*2) + 5); p++)
        cout << " ";
    cout << "-" << endl;

}

//The method start() is used to start the game.

void MiniBovo::start() {
    int timer = 0;
    //random number generator used to determine next board position to play
    unsigned int seed = time(NULL); //remember seed
    srand(seed); //apply seed	

    while (!complete()) {//game loop
        sleep(1); // wait 1 second 
        timer++;
        if (!began) began = true;
        cout << (noughtsTurn ? "O's turn" : "X's turn") << endl;
        play();
        displayBoard();
    }
    char win = winner(); //game is now complete, find out winner.
    if (win == 'N') cout << "There is no winner" << endl;
    else cout << "Player: " << ((win == 'X') ? "X" : "O") << " wins!" << endl;
    cout << "Game complete in " << timer << " seconds" << endl;
    cout << "Seed used: " << seed << endl; //print seed in case we need to rerun the same game.
}

//play() makes 1 move in the game

void MiniBovo::play() {
    if (noughtsTurn)
        playerO.play(board); //make playerO move.
    else
        playerX.play(board); //make playerX move.
    noughtsTurn = !noughtsTurn; //toggle current player.		
}

//complete() checks to see if the game is over

bool MiniBovo::complete() {
    if (!began)
        return false;
    if (winner() != 'N') //@TODO: make winner attribute to improve efficiency.
        return true;
    return boardFull(); //@TODO: make boardFull attribute to improve efficiency.
}

//boardFull() checks to see if every cell in the board either has a 0 or an X

bool MiniBovo::boardFull() {//@TODO: simplify using marked cell counter.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board.getPiece(i, j) == ' ')
                return false;
        }
    }
    return true;
}

//winner returns 'X' if X is the winner, 'O' if O is the winner and 'N' if a winner has not been found

char MiniBovo::winner() {
    //check rows
    for (int i = 0; i < SIZE; i++) {//for all rows
        for (int j = 0; j < SIZE - 2; j++) {//for all columns that can fit 3 symbol matches in a horizontal line
            if ((board.getPiece(i, j) != ' ')&&(board.getPiece(i, j) == board.getPiece(i, j + 1))&&(board.getPiece(i, j + 1) == board.getPiece(i, j + 2))) {
                return board.getPiece(i, j);
            }
        }
    }
    //check columns
    for (int i = 0; i < SIZE; i++) {//for all columns
        for (int j = 0; j < SIZE - 2; j++) {//for all rows that can fit 3 symbol matches in a vertical line
            if ((board.getPiece(j, i) != ' ')&&(board.getPiece(j, i) == board.getPiece(j + 1, i))&&(board.getPiece(j + 1, i) == board.getPiece(j + 2, i))) {
                return board.getPiece(j, i);
            }
        }
    }

    //check backslash diagonals
    for (int i = 0; i < SIZE - 2; i++) {//for all rows that can fit 3 symbol matches in a backslash diagonal line.
        for (int j = 0; j < SIZE - 2; j++) {//for all columns that can fit 3 symbol matches in backslash diagonal line.
            if ((board.getPiece(i, j) != ' ')&&(board.getPiece(i, j) == board.getPiece(i + 1, j + 1))&&(board.getPiece(i + 1, j + 1) == board.getPiece(i + 2, j + 2))) {
                return board.getPiece(i, j);
            }
        }
    }

    //check forwardslash diagonals	
    for (int i = 2; i < SIZE; i++) {//for all rows that can fit 3 symbol matches in a forwardslash diagonal line.
        for (int j = 0; j < SIZE - 2; j++) {//for all columns that can fit 3 symbol matches in a forwardslash diagonal line.
            if ((board.getPiece(i, j) != ' ')&&(board.getPiece(i, j) == board.getPiece(i - 1, j + 1))&&(board.getPiece(i - 1, j + 1) == board.getPiece(i - 2, j + 2))) {
                return board.getPiece(i, j);
            }
        }
    }
    return 'N'; //no winner found if we get here.		
}