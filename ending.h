#ifndef ending_h
#define ending_h2
#include "data/save.h"
void ending(RenderWindow&,int);
void ending(RenderWindow&win,int way)
{
    Texture e[38];
    inputEnding(e);
    if(way==5)
    {
        displayScreen(win,e,35,36);
        displayScreen(win,e,37);
    }
    else if(way==4)
    {
        displayScreen(win,e,17,18);
        displayScreen(win,e,19,20);
        displayScreen(win,e,21,22);
        displayScreen(win,e,23,24);
        displayScreen(win,e,25,26);
        displayScreen(win,e,27);
    }
    else
    {
        if(way==2||way==3)
        {
            displayScreen(win,e,1,2);
            displayScreen(win,e,3,4);
        }
        if(way==1||way==2)
        {
            displayScreen(win,e,5,6);
            displayScreen(win,e,7,8);
            displayScreen(win,e,9,10);
            displayScreen(win,e,11,12);
            displayScreen(win,e,13,14);
            displayScreen(win,e,13,15);
            displayScreen(win,e,13,16);
            displayScreen(win,e,0);
        }
        if(way==3)
        {
            displayScreen(win,e,28,29);
            displayScreen(win,e,30,31);
            displayScreen(win,e,32,33);
            displayScreen(win,e,34);
        }
    }
    win.close();
}
#endif // ending_h
