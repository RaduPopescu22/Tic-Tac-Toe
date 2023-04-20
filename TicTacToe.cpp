#include "TicTacToe.h"
#include <iostream>
#include <string>
#include <ctime>


void TicTacToe::createBoard(char board[3][3], const int &rowSize, const int &columnSize){
    for(int i = 0; i < rowSize; i++){
    for(int j = 0 ; j < columnSize; j++){
        board[i][j] = '-';
    }
    }
}

void TicTacToe::addToBoard(char board[3][3], const int &row, const int &column, const std::string user){
    char input {};
    if (user == "Player One"){
    input = 'X';
    }
    else{
    input = 'O';
    }
    board[row][column] = input;
    
}

void TicTacToe::printBoard(const char board[3][3], const int &rowSize, const int &columnSize){
    std::cout << "\n";
    for(int i = 0 ; i < rowSize ; i += 1){
    std::cout << "\t|";
    for(int j = 0 ; j < columnSize ; j += 1){
        std::cout << board[i][j] << '|';
    }
    std::cout << "\n";
    }
}

int TicTacToe::getInputColumn(const std::string &user){
    int column {};
    // proceeding with normal selection if not comp
    if(user != "Comp"){
    std::string response {};
    do{
        std::cout << user << ", left, middle or right?\n";
        std::getline(std::cin,response);
    }while (response != "left" && response != "middle" && response != "right");
    if (response == "left"){
        column = 0;
    }
    else if (response == "middle"){
        column = 1;
    }
    else{
        column = 2;
    }
    return column;
    }
    // assigning random number as comp move
    else{
    srand(time(NULL));
    column = (rand() % 3);
    return column;
    }

}

int TicTacToe::getInputRow(const std::string &user){
    int row {};
    // proceeding with normal selection if not comp
    if(user != "Comp"){
    std::string response {};
    do{
        std::cout << user << ", up, middle or down?\n";
        std::getline(std::cin,response);
    }while (response != "up" && response != "middle" && response != "down");
    if (response == "up"){
        row = 0;
    }
    else if (response == "middle"){
        row = 1;
    }
    else{
        row = 2;
    }
    return row;
    }
    // assigning random number as comp move
    else{
    srand(time(NULL));
    row = (rand() % 3);
    return row;
    }
}

void TicTacToe::checkEmpty(char board[3][3], int &rowAnswer, int &columnAnswer, const std::string &user){
    while(board[rowAnswer][columnAnswer] != '-'){
    columnAnswer = getInputColumn(user);
    rowAnswer = getInputRow(user);
    }
}
    
void TicTacToe::userSwitch(std::string &user, bool isComp){
    if(!isComp){
    if(user == "Player One"){
        user = "Player Two";
    }
    else{
        user = "Player One";
    }
    }
    else{
    if(user == "Player One"){
        user = "Comp";
    }
    else{
        user = "Player One";
    }
    }
}

bool TicTacToe::isWin(const char board[3][3], const std::string &user){
    char symbol {};
    if(user == "Player One"){
    symbol = 'X';
    }
    else{
    symbol = 'O';
    }

    bool horizontal1 = board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol;
    bool horizontal2 = board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol; 
    bool horizontal3 = board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol;
    
    bool vertical1 = board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol;
    bool vertical2 = board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol;
    bool vertical3 = board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol;
    
    bool diagonal1 = board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol;
    bool diagonal2 = board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol;
    
    bool hWin = (horizontal1 || horizontal2 || horizontal3);
    bool vWin = (vertical1 || vertical2 || vertical3);
    bool dWin = (diagonal1 || diagonal2);

    if(hWin || vWin || dWin){
    return true;
    }
    else{
    return false;
    }
}

bool TicTacToe::isTie(const char board[3][3], const int &rowSize, const int &columnSize){
    int emptycount {};
    for(int i = 0; i < rowSize; i += 1){
    for(int j = 0; j < columnSize; j += 1){
        if (board[i][j] == '-'){
        emptycount += 1;
        } 
    }
    }
    if (!emptycount){
    return true;
    }
    else{
    return false;
    }
}

void TicTacToe::tieMessage(){
    std::cout << '\n' << "\tGame over ! !\n" << "\tIt's a tie ! ! !!\n";
}

void TicTacToe::winMessage(const std::string &user){
    std::cout << "\n\tCongratulations " << user << " ! !! !" << "\n\tYOU WON! !!! !!\n"; 
}

