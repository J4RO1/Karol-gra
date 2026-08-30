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
int t[wymiar][wymiar];
for(int i=0;i<wymiar;i++){
    for(int j=0;j<wymiar;j++){
        t[i][j]=0;
    }
}
t[wymiar-6][(wymiar+1)/2-1]=1;
t[wymiar-5][(wymiar+1)/2-1]=2;
t[wymiar-4][(wymiar+1)/2-1]=3;
int wynik=3;
int koniec=wynik+limit;
int kierunek=72;
bool przegrana=false;
bool wygrana=false;
while(true){
    if(_kbhit()){
        kierunek=_getch();
        if(kierunek==224){
            kierunek=_getch();
        }
    }
    system("cls");
    for(int i=0;i<wymiar;i++){
        for(int j=0;j<wymiar;j++){
            if(t[i][j]==wynik) t[i][j]=0;
            if(t[i][j]!=0) t[i][j]=t[i][j]+1;
        }
    }
    for(int i=0;i<wymiar;i++){
        for(int j=0;j<wymiar;j++){
            if(t[i][j]==2){
                if(kierunek==72){
                    if(t[i-1][j]==0) t[i-1][j]=1;
                    else if(t[i-1][j]==3) t[i+1][j]=1;
                         else przegrana=true;
                }
                else if(kierunek==75){
                        if(t[i][j-1]==0) t[i][j-1]=1;
                        else if(t[i][j-1]==3) t[i][j+1]=1;
                             else przegrana=true;
                    }
                else if(kierunek==77){
                        if(t[i][j+1]==0) t[i][j+1]=1;
                        else if(t[i][j+1]==3) t[i][j-1]=1;
                             else przegrana=true;
                    }
                else if(kierunek==80){
                        if(t[i+1][j]==0) t[i+1][j]=1;
                        else if(t[i+1][j]==3) t[i-1][j]=1;
                             else przegrana=true;
                    }
            }
        }
    }
    if(przegrana || wygrana) break;
    for(int i=0;i<wymiar;i++){
        for(int j=0;j<wymiar;j++){
            if(t[i][j]!=0) cout<<"#";
            else cout<<" ";
        }
        cout<<endl;
    }
    Sleep(250);
}
system("cls");
if(przegrana) cout<<"Przegrales!";
}
