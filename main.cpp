#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
int main()
{
cout<<"Witaj drogi graczu w grze o wezu Jimie!\nJim jest bardzo glodny, wiec pomoz mu znalezc i zjesc wszystkie jablka!\n\nWcisnij dowolny przycisk.";
_getch();
int opcje[]={10,15,20,25};
int wybrana=0;
int liczba_opcji=4;
while(true){
    system("cls");
    cout<<"No to zaczynamy! Najpierw, jakie wymiary ma miec kwadratowa plansza dla Jima?\n(pssst, wybieraj strzalkami i nacisnij enter)\n\n";
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
int wymiar=opcje[wybrana];
int limit;
cout<<"Teraz wybierz, ile jablek chcesz, zeby Jim zjadl.\n";
while(true){
    cin>>limit;
    if(limit<1 || limit>1 && limit<5) cout<<"Nie za malo? Daj Jimowi zjesc choc 5 jablek!\n";
    else if(limit>50) cout<<"Nie za duzo? Jim sie przeje! Daj mu nie wiecej niz 50.\n";
    if(limit==1 || limit>=5 && limit<=50) break;
}
system("cls");
cout<<"No to zaczynajmy!\n\nWcisnij dowolny przycisk.";
}
