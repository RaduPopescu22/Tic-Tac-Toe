#include "TicTacToe.h"
#include <iostream>
#include <string>
#include <ctime>


int main(){
  TicTacToe tictactoe;
  // Choosing the gamemode and holding info in isComp to use when switching
  std::string gameMode {};
  bool isComp = false;
  do{
    std::cout << "Please choose your game mode -> type Comp or PVP\n";
    std::getline(std::cin,gameMode);
  }while(gameMode != "Comp" && gameMode != "PVP");
  
  if(gameMode == "Comp"){
    isComp = true;
  }
  // Creating the board
  std::string user {"Player One"};
  tictactoe.createBoard(tictactoe.board,tictactoe.rowSize,tictactoe.columnSize);
  
  // Game loop starts
  while (true){
    int column = tictactoe.getInputColumn(user);
    int row = tictactoe.getInputRow(user);

    tictactoe.checkEmpty(tictactoe.board,row,column,user);
    tictactoe.addToBoard(tictactoe.board,row,column,user);
    tictactoe.printBoard(tictactoe.board,tictactoe.rowSize,tictactoe.columnSize);
    
    // Win/tie check, if not, continue looping
    if(tictactoe.isWin(tictactoe.board,user)){
      tictactoe.winMessage(user);
      break;
    }
    else if(tictactoe.isTie(tictactoe.board,tictactoe.rowSize,tictactoe.columnSize)){
      tictactoe.tieMessage();
      break;
    }
    tictactoe.userSwitch(user,isComp);
  }

  return 0;
}





