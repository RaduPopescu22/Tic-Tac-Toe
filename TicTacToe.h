#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <string>


class TicTacToe{

  public:
    
    char board[3][3] {};
    const int columnSize = sizeof(board[0]) / sizeof(board[0][0]);
    const int rowSize = sizeof(board) / sizeof(board[0]);

    void createBoard(char board[3][3], const int &rowSize, const int &columnSize);

    void addToBoard(char board[3][3], const int &row, const int &column, const std::string user);

    void printBoard(const char board[3][3], const int &rowSize, const int &columnSize);

    int getInputColumn(const std::string &user);

    int getInputRow(const std::string &user);

    void checkEmpty(char board[3][3], int &rowAnswer, int &columnAnswer, const std::string &user);
      
    void userSwitch(std::string &user, bool isComp);

    bool isWin(const char board[3][3], const std::string &user);

    bool isTie(const char board[3][3], const int &rowSize, const int &columnSize);

    void tieMessage();

    void winMessage(const std::string &user);

};


#endif