#ifndef gui_h
#define gui_h
#include <SFML/Graphics.hpp>
#include <windows.h>
using namespace std;
using namespace sf;

Color Grey(125,125,125);
const string pName="image/main/Storyboard-";
void clickOnce(RenderWindow &);
void displayScreen(RenderWindow &,Texture[],int,int=0,bool=true);
void clickOnce(RenderWindow &win)
{
    //cerr<<"in";
    Sleep(1);
    Event e;
    if(win.pollEvent(e))
    {
        Vector2i pos=Mouse::getPosition();
        if(e.type==Event::Closed)
        {
            win.close();
            return;
        }
        if(e.type==Event::MouseButtonPressed)
            if(e.key.code==Mouse::Left)
            {
                //cerr<<pos.x<<pos.y<<endl;
                return;
            }
    }
    return clickOnce(win);
}
void displayScreen(RenderWindow &win,Texture t[],int a,int b,bool c)
{
    win.clear(Grey);
    Sprite pic(t[a]);
    win.draw(pic);
    if(b)
    {
        Sprite tex(t[b]);
        tex.setPosition(0,630);
        win.draw(tex);

    }
    win.display();
    if(c)
        clickOnce(win);

}

#endif // gui_h
