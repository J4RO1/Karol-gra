#include <iostream>
#include <conio.h>
#include <windows.h>
void WrocNaPoczatek(){
    COORD pozycja;
    pozycja.X=1;
    pozycja.Y=1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pozycja);
}
void HideCursor()
{
    CONSOLE_CURSOR_INFO info={1,false};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&info);
}
using namespace std;
int main()
{
    HideCursor();
    cout<<"1234567890";
    _getch();
    WrocNaPoczatek();
    _getch();
    cout<<2;
}
