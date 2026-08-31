#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
void Ustaw(int x,int y)
{
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
int t[15][15];
int main()
{
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            cout<<t[i][j];
        }
        cout<<"\n";
    }
    Ustaw(0,0);
    int ax=0,ay=0;
    while(true){
        int k=_getch();
        if(k==224) k=_getch();
        if(k==72) Ustaw(ax,--ay);
        else if(k==75) Ustaw(--ax,ay);
        else if(k==77) Ustaw(++ax,ay);
        else if(k==80) Ustaw(ax,++ay);
    }
}
