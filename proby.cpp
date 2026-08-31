#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
int main()
{
    int i=0;
    while(true){
        cout<<i;
        i=(i+1)%10;
        Sleep(100);
    }
}
