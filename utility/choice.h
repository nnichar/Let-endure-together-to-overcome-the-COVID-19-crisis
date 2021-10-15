#ifndef choice_h
#define choice_h
#include <conio.h>
#include <iostream>
#include "print.h"
#include "colour.h"
#include "gui.h"
#include <time.h>
const string sel="Select your way ( A or B )";
bool choice(RenderWindow&,string,string,string=sel);
bool choice(RenderWindow&win,string a,string b,string q)
{
    bool com=0;

    string t="You was selected ";
    resetColour();
    print(q);
    print("A ) "+a);
    print("B ) "+b);
    //setColour(red,black);
    try
    {
        while(!com)
        {
            Vector2i pos=Mouse::getPosition(win);
            Event e;
            while(win.pollEvent(e))
            {
                if(e.type==Event::Closed)
                {
                    win.close();
                    return 0;
                }
                if(e.type==Event::MouseButtonPressed)
                {
                    if(e.key.code==Mouse::Left)
                    {
                        if(pos.x>40&&pos.x<400&&pos.y>655&&pos.y<765)
                        {
                            t=t+a;
                            throw true;
                        }
                        if(pos.x>440&&pos.x<800&&pos.y>655&&pos.y<765)
                        {
                            t=t+b;
                            throw false;
                        }
                    }
                }
            }
        }
    }
    catch(bool a)
    {
        setColour(yellow,black);
        print(t);
        resetColour();
        return a;
    }
}

#endif // choice
