#include "classes.cpp"
#include "functions.cpp"

int main(){
    Player player1, player2;
    Player *playingPlayer;
    Gameboard gameboard;
    
    // Get players
    player1.setName(getPlayerName());
    player1.setPlayerChar('x');
    player1.printInfo();
    
    player2.setName(getPlayerName());
    player2.setPlayerChar('o');
    player2.printInfo();
    
    playingPlayer = &player1;
    int playRow, playColumn;
    int *playRowAddr = &playRow;
    int *playColumnAddr = &playColumn;
    for (int i = 0; i < 16; i++){
        getPlayPosition(playRowAddr, playColumnAddr);
        cout << playingPlayer->getName() <<" playing: "<< playRow << "," << playColumn;
        gameboard.setGameSpace(playRow, playColumn, playingPlayer->getPlayerChar());
        if (gameboard.checkForWinner(playingPlayer->getPlayerChar()) == 1){
            cout << playingPlayer->getName() << " Wins!!";
            break;
        }else{
            if (playingPlayer == &player1){ playingPlayer = &player2;}
            else {playingPlayer = &player1;}
        }
    }
    cout << "It's a tie!";
    gameboard.printBoard();
    
    
    return 0;
}