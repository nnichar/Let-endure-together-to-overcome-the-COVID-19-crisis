#ifndef colour_h
#define colour_h
#include <windows.h>
#include <string>
using namespace std;
enum clist {black,dblue,dgreen,aqua,dred,dviolet,dyellow,gray,dgray,blue,green,cyan,red,violet,yellow,white};
void setColour(enum clist text,enum clist back);
void resetColour();
void resetAllColour();
void setColour(enum clist text,enum clist back)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back*16+text);
}
void resetColour()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), black*16+ white);
}
void resetAllColour()
{
    system("color 0F");
}
#endif // colour_h
