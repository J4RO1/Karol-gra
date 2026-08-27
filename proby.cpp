#include <iostream>
#include <conio.h>
using namespace std;
int main(){
string opcje[]={"Nowa gra","Wczytaj gre","Ustawienia","Wyjscie"};
int wybrana=0;
int liczba_opcji=4;
while(true){
    system("cls");
    cout<<"===================="<<endl;
    cout<<"       WYBIERZ"<<endl;
    cout<<"====================\n"<<endl;
    for(int i=0;i<liczba_opcji;i++){
        if(i==wybrana) cout<<"> ";
        else cout<<"  ";
        cout<<opcje[i]<<endl;
    }
    int klawisz=_getch();
    if(klawisz==224){
        klawisz=_getch();
        if(klawisz==72) wybrana=(wybrana+liczba_opcji-1)%liczba_opcji;
        if(klawisz==80) wybrana=(wybrana+1)%liczba_opcji;
    }
    if(klawisz==13) break;
}
system("cls");
cout<<"wybrano: "<<opcje[wybrana];
}
