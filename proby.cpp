#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
int main(){
string opcje[]={"10","20","30"};
int wybrana=0;
int liczba_opcji=3;
while(true){
    system("cls");
    cout<<"Jakie wymiary ma miec plansza?"<<endl<<endl;
    for(int i=0;i<liczba_opcji;i++){
        if(i==wybrana) cout<<"> "<<opcje[i]<<endl;
        else cout<<"  "<<opcje[i]<<endl;
    }
    int klawisz=_getch();
    if(klawisz==224){
        klawisz=_getch();
        if(klawisz==72) wybrana=(wybrana+2)%3;
        if(klawisz==80) wybrana=(wybrana+1)%3;
    }
    else if(klawisz==13) break;
}
system("cls");
cout<<"Wybrales: "<<opcje[wybrana]<<endl;

}
