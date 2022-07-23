#include <iostream>
#include <string>
using namespace std;

class Player {
    string name;
    char playerChar;
    
    public:
      void setName(string nameIn);
      void setPlayerChar(char playerCharIn);
      char getPlayerChar();
      string getName();
      void printInfo();
};

void Player::setName(string nameIn){
    name = nameIn;
}


void Player::setPlayerChar(char playerCharIn){
    playerChar = playerCharIn;
}


string Player::getName(){
    return name;
}


char Player::getPlayerChar(){
    return playerChar;
}

void Player::printInfo(){
    cout << name << " ( " << playerChar << " ) ";
}

class Gameboard{
    char gameSpace[4][4];
    
    public:
      Gameboard();
      void setGameSpace(int row, int column, char playersChar);
      char getGameSpace(int row, int column);
      int checkForWinner(char playersChar);
      void printBoard();
};

Gameboard::Gameboard(){
    for (int i = 0; i<4; i++){
        for (int j = 0; j < 4; j++){
            gameSpace[i][j] = '.';
        }
    }
}

void Gameboard::setGameSpace(int row, int column, char playersChar){
    if (gameSpace[row][column] == '.'){
        gameSpace[row][column] = playersChar;
    }else{
        cout << "Invalid move, space already taken";
    }
}

char Gameboard::getGameSpace(int row, int column){
    return gameSpace[row][column];
}

int Gameboard::checkForWinner(char playersChar){
    // Check rows
    int count = 0;
    for (int i = 0; i<4; i++){
        count = 0;
        for (int j = 0; j < 4; j++){
            if (gameSpace[i][j] == playersChar){
                count++;
            }else{
                break;
            }
        }
        if (count == 4){
            return 1;
        }
    }
    
    // Check columns
    for (int i = 0; i<4; i++){
        count = 0;
        for (int j = 0; j < 4; j++){
            if (gameSpace[j][i] == playersChar){
                count++;
            }else{
                break;
            }
        }
        if (count == 4){
            return 1;
        }
    }
    
    // Check diagonals
    count = 0;
    for (int j = 0; j < 4; j++){
        if (gameSpace[j][j] == playersChar){
            count++;
        }else{
            break;
        }
    }
    if (count == 4){
        return 1;
    }
    
    count = 0;
    for (int j = 0; j < 4; j++){
        if (gameSpace[j][3-j] == playersChar){
            count++;
        }else{
            break;
        }
    }
    if (count == 4){
        return 1;
    }

    
    
    return 0;
}

void Gameboard::printBoard(){
    cout << " | ";
    for (int i = 0; i<4; i++){
        for (int j = 0; j < 4; j++){
            cout << " " << gameSpace[i][j];
        }
        cout << " | \n";
    }
}
