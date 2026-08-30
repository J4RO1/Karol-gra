#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
int main()
{
while(true){
    cout<<"program se leci\n";
    if(_kbhit()){
        int klawisz=_getch();
        cout<<"Wcisnieto: "<<klawisz<<endl;
    }
    Sleep(250);
}
}
