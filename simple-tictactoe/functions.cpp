
#include <iostream>
#include <string>

string getPlayerName(){
    string playerName;
    cout << "Enter player name: ";
    cin >> playerName;
    return playerName;
}

void getPlayPosition(int *row, int *column){
    int rowIn, columnIn;
    cin >> rowIn;
    cin >> columnIn;
    *row = rowIn;
    *column = columnIn;
}