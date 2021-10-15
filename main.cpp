#include "includes.h"
int main()
{
    resetAllColour();
    srand(time(NULL));
    bool con=1;
    string name;
    do
    {
        try
        {
            resetColour();
            cout<<"What's your name ? ( 5 - 20 characters )\n> ";
            setColour(yellow,black);
            getline(cin,name);
            if(name.size()<5||name.size()>20)
                throw "Error";
            con=0;
            resetColour();
        }
        catch(...)
        {
            setColour(red,black);
            cout<<"Invalid input please try again\n";
        }
    }
    while(con);

    ii highScore[11];
    string leader[11];

    inputHighScore(highScore,leader);
    user player(name);
    game(player,highScore,leader);
    ///////////////////save//////////////////
    player.showResult();
    player.saveRecord(highScore,leader);
    sortHighScore(highScore,leader);
    readHighScore(highScore,leader);
    outputHighScore(highScore,leader);
    /////////////////save//////////////////////
}
