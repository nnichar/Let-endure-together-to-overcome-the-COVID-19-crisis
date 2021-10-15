#ifndef minigame_h
#define minigame_h
#include "data/save.h"
using namespace sf;
bool minigame(int &);
int calScore(int select[3][4]);
bool minigame(int &score)
{
    RenderWindow win(VideoMode(843,789),"mini game");
    Texture m,p[3],l[2],n;
    m.loadFromFile("image/minigame/main.jpg");
    n.loadFromFile("image/minigame/next_button.jpg");
    Sprite mainMenu(m);
    Sprite page[3];
    Sprite next(n);
    for(int i=0; i<3; i++)
    {
        (p+i)->loadFromFile("image/minigame/page_"+itostr(i+1)+".jpg");
        (page+i)->setTexture(p[i]);
    }
    for(int i=0; i<2; i++)
    {
        l[i].loadFromFile("image/minigame/line_"+itostr(i+1)+".jpg");
    }
    int count=0;
    win.clear();
    win.draw(mainMenu);
    win.display();
    int select[3][4]=
    {
        0,0,0,0,
        0,0,0,0,
        0,0,0,0,
    };
    Sprite line[3][4];
    Sprite mouse(l[0]);
    mouse.setTextureRect(IntRect(0,0,1,1));
    while(win.isOpen())
    {
        //cerr<<count;
        Event e;
        Vector2i pos=Mouse::getPosition(win);
        mouse.setPosition(pos.x,pos.y);
        while(win.pollEvent(e))
        {
            usleep(10);
            if(e.type==Event::Closed)
            {
                win.close();
                exit(1);
            }
            if(e.type==Event::MouseButtonPressed)
            {
                if(e.key.code==Mouse::Left)
                {
                    // cout<<pos.x<<":"<<pos.y<<endl;
                    if(count==0)
                    {
                        if(pos.x>160&&pos.x<680&&pos.y>260&&pos.y<340)
                        {
                            count=1;
                            win.draw(page[count-1]);
                            win.display();
                        }
                        for(int i=0; i<4; i++)
                        {
                            line[0][i].setTexture(l[0]);
                            line[0][i].setPosition(0,-100);
                        }
                        continue;
                    }
                    if(count==1)
                    {
                        bool com=1;
                        int choice=0;////127 392 435 700
                        int y[4]= {190,375,560,710};
                        if(pos.y>130&&pos.y<y[0])
                            choice=1;
                        if(pos.y>315&&pos.y<y[1])
                            choice=2;
                        if(pos.y>500&&pos.y<y[2])
                            choice=3;
                        if(pos.y>650&&pos.y<y[3])
                            choice=4;
                        if(choice)
                        {
                            if(pos.x>127&&pos.x<392)
                                select[count-1][choice-1]=1;
                            if(pos.x>435&&pos.x<700)
                                select[count-1][choice-1]=2;
                        }
                        for(int i=0; i<4; i++)
                        {
                            //cout<<i;
                            if(select[count-1][i])
                                line[count-1][i].setPosition(select[count-1][i]==1? 127:435,y[i]+15);
                            else
                                com=0;
                        }
                        win.draw(page[count-1]);
                        for(int i=0; i<4; i++)
                            win.draw(line[count-1][i]);
                        if(com)
                        {
                            next.setPosition(700,730);
                            win.draw(next);

                            if(next.getGlobalBounds().intersects(mouse.getGlobalBounds()))
                            {
                                line[1][0].setTexture(l[0]);
                                line[1][1].setTexture(l[1]);
                                line[1][2].setTexture(l[1]);
                                count++;
                                win.draw(page[count-1]);
                                win.display();

                                continue;
                            }
                        }
                        win.display();

                    }
                    if(count==2)
                    {
                        bool com=1;
                        int choice=0;////127 392 435 700
                        int y[3]= {240,400,590};
                        if(pos.y>y[0]&&pos.y<y[0]+60)
                            choice=1;
                        if(pos.y>y[1]&&pos.y<y[1]+60)
                            choice=2;
                        if(pos.y>y[2]&&pos.y<y[2]+60)
                            choice=3;
                        if(choice==1)
                        {
                            if(pos.x>130&&pos.x<392)
                                select[count-1][0]=1;
                            if(pos.x>444&&pos.x<700)
                                select[count-1][0]=2;
                        }
                        int x[2][5]=
                        {
                            80,275,435,589,770,
                            160,275,385,505,690
                        };
                        int platx[2][4]=
                        {
                            140,320,485,620,
                            180,285,395,538
                        };
                        if(choice==2||choice==3)
                        {
                            if(pos.x>x[choice-2][0]&&pos.x<x[choice-2][1])
                                select[count-1][choice-1]=1;
                            else if(pos.x<x[choice-2][2])
                                select[count-1][choice-1]=2;
                            else if(pos.x<x[choice-2][3])
                                select[count-1][choice-1]=3;
                            else if(pos.x<x[choice-2][4])
                                select[count-1][choice-1]=4;
                        }

                        if(select[count-1][0])
                        {
                            (line[count-1][0]).setPosition(select[count-1][0]==1? 130:444,y[0]+75);
                        }
                        else
                            com=0;
                        for(int i=1; i<=2; i++)
                        {
                            if(select[count-1][i])
                            {
                                line[count-1][i].setPosition(platx[i-1][select[count-1][i]-1],y[i]+75);
                            }
                            else
                                com=0;
                        }
                        win.draw(page[count-1]);
                        for(int i=0; i<3; i++)
                            if(select[count-1][i])
                                win.draw(line[count-1][i]);
                        if(com)
                        {
                            next.setPosition(700,730);
                            win.draw(next);

                            if(next.getGlobalBounds().intersects(mouse.getGlobalBounds()))
                            {
                                count++;
                                for(int i=0; i<4; i++)
                                    line[count-1][i].setTexture(l[1]);
                                win.draw(page[count-1]);
                                win.display();
                                continue;
                            }
                        }
                        win.display();
                    }
                    if(count==3)
                    {
                        bool com=1;
                        int choice=0;////127 392 435 700
                        int y[4]= {130,280,450,600};
                        if(pos.y>y[0]&&pos.y<y[0]+60)
                            choice=1;
                        if(pos.y>y[1]&&pos.y<y[1]+60)
                            choice=2;
                        if(pos.y>y[2]&&pos.y<y[2]+60)
                            choice=3;
                        if(pos.y>y[3]&&pos.y<y[3]+60)
                            choice=4;
                        if(choice==1)
                        {
                            if(pos.x>170&&pos.x<450)
                                select[count-1][0]=1;
                            if(pos.x>450&&pos.x<650)
                                select[count-1][0]=2;
                        }
                        int x[3][4]=
                        {
                            155,295,435,705,
                            155,290,435,685,
                            105,250,495,735

                        };
                        int platx[3][3]=
                        {
                            190,330,515,
                            180,320,520,
                            135,325,575,
                        };
                        if(choice==2||choice==3||choice==4)
                        {
                            if(pos.x>x[choice-2][0]&&pos.x<x[choice-2][1])
                                select[count-1][choice-1]=1;
                            else if(pos.x<x[choice-2][2])
                                select[count-1][choice-1]=2;
                            else if(pos.x<x[choice-2][3])
                                select[count-1][choice-1]=3;
                        }

                        if(select[count-1][0])
                        {
                            (line[count-1][0]).setPosition(select[count-1][0]==1? 284:510,y[0]+75);
                        }
                        else
                            com=0;
                        for(int i=1; i<=3; i++)
                        {
                            if(select[count-1][i])
                            {
                                line[count-1][i].setPosition(platx[i-1][select[count-1][i]-1],y[i]+75);
                            }
                            else
                                com=0;
                        }
                        win.draw(page[count-1]);
                        for(int i=0; i<4; i++)
                            if(select[count-1][i])
                                win.draw(line[count-1][i]);
                        if(com)
                        {
                            next.setPosition(700,730);
                            win.draw(next);

                            if(next.getGlobalBounds().intersects(mouse.getGlobalBounds()))
                            {
                                score=calScore(select);
                                //   cout<<"mini score:"<<score<<endl;
                                win.close();
                            }
                        }
                        win.display();
                    }
                }
            }
        }
    }
    return score>=1800;
}
int calScore(int select[3][4])
{
    int ans[3][4]=
    {
        1,1,2,1,
        2,2,3,0,
        1,2,2,2
    };
    int point=0;
    for(int i=0; i<3; i++)
        for(int j=0; j<4; j++)
            if(select[i][j]==ans[i][j])
                point++;
    return point*300;
}


#endif // minigame_h
