#ifndef save_h
#define save_h
#include <fstream>
#include <iostream>
#include <iomanip>
#include "../utility/compare.h"
#include "../utility/convert.h"
#include "../utility/gui.h"
#define imgCount 121
using namespace std;
typedef pair<int,int> ii;
void inputEnding(Texture []);
void inputDialog(string dialog[]);
void inputTexture(Texture[]);
void inputHighScore(ii highScore[],string leader[]);
void readHighScore(ii highScore[],string leader[]);
void sortHighScore(ii highScore[],string leader[]);
void outputHighScore(ii highScore[],string leader[]);
/*
void setd()
{
    ofstream fileName("data/data.txt");
    if(fileName.is_open())
    {
        for(int i=0; i<=54; i++)
        {
            for(int j=0; j<20; j++)
            {
                if(i>9)
                    j++;
                fileName << i;
            }
            fileName << endl;
        }
        fileName.close();
    }
    else
    {
        cout<<"Unable to open\n";
    }
}
*/
void inputDialog(string dialog[])
{
    ifstream fileName("data/data.txt");
    if(fileName.is_open())
    {
        for(int i=0; i<=54; i++)
        {
            getline(fileName,dialog[i]);
        }
        fileName.close();
    }
    else
    {
        cout<<"Unable to open\n";
    }
}
void inputTexture(Texture t[])
{
    cout<<"loading game please wait\n";
    for(int i=1; i<=imgCount; i++)
    {
        cout<<setprecision(4)<<float(i)/imgCount*100<<" %";
        string temp=pName;
        if(i<10)
            temp+='0';
        t[i].loadFromFile(temp+itostr(i)+".jpg");
        if(float(i)/imgCount!=1)
            for(int j=0; j<10; j++)
                cout<<"\b \b";
    }
    cout<<"\nloading complete\n";
}
void inputEnding(Texture t[])
{
    cout<<"loading ending scene please wait\n";
    for(int i=0; i<=37; i++)
    {
        string temp="image/ending/ending-";
        //if(!i)temp+='0';
        t[i].loadFromFile(temp+itostr(i)+".jpg");
    }
    cout<<"loading complete\n";
}
void inputHighScore(ii highScore[],string leader[])
{
    string temp;
    ifstream fileName("data/highScore.txt");
    if(fileName.is_open())
    {
        for(int i=0; i<10; i++)
        {
            getline(fileName,leader[i]);
            getline(fileName,temp);
            highScore[i].first=strtoi(temp);
            getline(fileName,temp);
            highScore[i].second=strtoi(temp);

        }

        fileName.close();
    }
    else
    {
        cout<<"Unable to open\n";
    }
}
void readHighScore(ii highScore[],string leader[])
{
    cout<<"LEADER BOARD\n";
    cout<<setw(21)<<left<<"Name";
    cout<<"Score  Week\n";


    for(int i=0; i<10; i++)
    {
        cout<<setw(20)<<left<<leader[i]<<" ";
        cout<<setw(5)<<right<<highScore[i].first;
        cout<<setw(5)<<right<<highScore[i].second<<endl;
    }
    cout<<endl;
}
void sortHighScore(ii highScore[],string leader[])//////////sort///
{
    for(int i=1; i<11; i++)
    {
        int j=i;
        if(iicmp(highScore[j],highScore[j-1]))
        {
            string temp=leader[i];
            ii temp2=highScore[i];
            while(iicmp(temp2,highScore[j-1])&&j>0)
            {
                leader[j]=leader[j-1];
                highScore[j]=highScore[j-1];
                j--;
            }
            leader[j]=temp;
            highScore[j]=temp2;
        }
    }
}
void outputHighScore(ii highScore[],string leader[])
{
    ofstream fileName("data/highScore.txt");
    if(fileName.is_open())
    {
        for(int i=0; i<10; i++)
        {
            fileName << leader[i] <<endl;
            fileName << itostr(highScore[i].first) <<endl;
            fileName << itostr(highScore[i].second) <<endl;
        }
        fileName.close();
    }
    else
    {
        cout<<"Unable to open\n";
    }
}


#endif // save_h
