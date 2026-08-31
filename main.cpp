#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
void GoToStart()
{
    COORD pozycja;
    pozycja.X=0;
    pozycja.Y=0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pozycja);
}
void HideCursor()
{
    CONSOLE_CURSOR_INFO info_nie={1,false};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&info_nie);
}
void ShowCursor()
{
    CONSOLE_CURSOR_INFO info_tak={1,true};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&info_tak);
}
int main()
{
srand(time(NULL));
cout<<"Witaj drogi graczu w grze o wezu Jimie!\nJim jest bardzo glodny, wiec pomoz mu znalezc i zjesc wszystkie jablka!\n\nWcisnij dowolny przycisk.";
_getch();
int opcje[]={10,15,20,25};
int wybrana=0;
int liczba_opcji=4;
system("cls");
HideCursor();
while(true){
    GoToStart();
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
ShowCursor();
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
int koniec=limit;
int kierunek=72;
bool przegrana=false;
bool wygrana=false;
int wsp_i1=wymiar-6,wsp_j1=(wymiar+1)/2-1;
int wsp_iost=wymiar-4,wsp_jost=(wymiar+1)/2-1;
int wsp_i_jab,wsp_j_jab;
int tymcz_kier;
while(true){
    wsp_i_jab=rand()%wymiar;
    wsp_j_jab=rand()%wymiar;
    if(t[wsp_i_jab][wsp_j_jab]==0){
        t[wsp_i_jab][wsp_j_jab]=1111;
        break;
    }
}
_getch();
HideCursor();
system("cls");
while(true){
    bool czy_jablko=false;
    if(_kbhit()){
        tymcz_kier=kierunek;
        kierunek=_getch();
        if(kierunek==224){
            kierunek=_getch();
        }
        else kierunek=tymcz_kier;
    }
    GoToStart();
    for(int i=0;i<wymiar;i++){
        for(int j=0;j<wymiar;j++){
            if(t[i][j]!=0) t[i][j]=t[i][j]+1;
        }
    }
    {
        int i=wsp_i1;
        int j=wsp_j1;
                if(kierunek==72){
                    if(wsp_i1==0){
                        przegrana=true;
                    }
                    else if(t[i-1][j]==0){
                        t[i-1][j]=1;
                        wsp_i1=i-1;
                    }
                    else if(t[i-1][j]==3){
                            kierunek=80;
                            if(wsp_i1==wymiar-1){
                                przegrana=true;
                            }
                            else if(t[i+1][j]==0){
                                t[i+1][j]=1;
                                wsp_i1=i+1;
                            }
                            else if(t[i+1][j]<1000) przegrana=true;
                            else{
                                wynik++;
                                t[i+1][j]=1;
                                wsp_i1=i+1;
                                while(true){
                                    wsp_i_jab=rand()%wymiar;
                                    wsp_j_jab=rand()%wymiar;
                                    if(t[wsp_i_jab][wsp_j_jab]==0){
                                        t[wsp_i_jab][wsp_j_jab]=1111;
                                        break;
                                    }
                                }
                                czy_jablko=true;
                              }
                         }
                         else if(t[i-1][j]<1000) przegrana=true;
                              else{
                                wynik++;
                                t[i-1][j]=1;
                                wsp_i1=i-1;
                                while(true){
                                    wsp_i_jab=rand()%wymiar;
                                    wsp_j_jab=rand()%wymiar;
                                    if(t[wsp_i_jab][wsp_j_jab]==0){
                                        t[wsp_i_jab][wsp_j_jab]=1111;
                                        break;
                                    }
                                }
                                czy_jablko=true;
                              }
                }
                else if(kierunek==75){
                    if(wsp_j1==0){
                        przegrana=true;
                    }
                    else if(t[i][j-1]==0){
                        t[i][j-1]=1;
                        wsp_j1=j-1;
                    }
                    else if(t[i][j-1]==3){
                            kierunek=77;
                            if(wsp_j1==wymiar-1){
                                przegrana=true;
                            }
                            else if(t[i][j+1]==0){
                                t[i][j+1]=1;
                                wsp_j1=j+1;
                            }
                            else if(t[i][j+1]<1000) przegrana=true;
                            else{
                                wynik++;
                                t[i][j+1]=1;
                                wsp_j1=j+1;
                                while(true){
                                    wsp_i_jab=rand()%wymiar;
                                    wsp_j_jab=rand()%wymiar;
                                    if(t[wsp_i_jab][wsp_j_jab]==0){
                                        t[wsp_i_jab][wsp_j_jab]=1111;
                                        break;
                                    }
                                }
                                czy_jablko=true;
                              }
                         }
                         else if(t[i][j-1]<1000) przegrana=true;
                              else{
                                wynik++;
                                t[i][j-1]=1;
                                wsp_j1=j-1;
                                while(true){
                                    wsp_i_jab=rand()%wymiar;
                                    wsp_j_jab=rand()%wymiar;
                                    if(t[wsp_i_jab][wsp_j_jab]==0){
                                        t[wsp_i_jab][wsp_j_jab]=1111;
                                        break;
                                    }
                                }
                                czy_jablko=true;
                              }
                }
                else if(kierunek==77){
                    if(wsp_j1==wymiar-1){
                        przegrana=true;
                    }
                    else if(t[i][j+1]==0){
                        t[i][j+1]=1;
                        wsp_j1=j+1;
                    }
                    else if(t[i][j+1]==3){
                            kierunek=75;
                            if(wsp_j1==0){
                                przegrana=true;
                            }
                            else if(t[i][j-1]==0){
                                t[i][j-1]=1;
                                wsp_j1=j-1;
                            }
                            else if(t[i][j-1]<1000) przegrana=true;
                            else{
                                wynik++;
                                t[i][j-1]=1;
                                wsp_j1=j-1;
                                while(true){
                                    wsp_i_jab=rand()%wymiar;
                                    wsp_j_jab=rand()%wymiar;
                                    if(t[wsp_i_jab][wsp_j_jab]==0){
                                        t[wsp_i_jab][wsp_j_jab]=1111;
                                        break;
                                    }
                                }
                                czy_jablko=true;
                              }
                         }
                         else if(t[i][j+1]<1000) przegrana=true;
                              else{
                                wynik++;
                                t[i][j+1]=1;
                                wsp_j1=j+1;
                                while(true){
                                    wsp_i_jab=rand()%wymiar;
                                    wsp_j_jab=rand()%wymiar;
                                    if(t[wsp_i_jab][wsp_j_jab]==0){
                                        t[wsp_i_jab][wsp_j_jab]=1111;
                                        break;
                                    }
                                }
                                czy_jablko=true;
                              }
                }
                else if(kierunek==80){
                    if(wsp_i1==wymiar-1){
                        przegrana=true;
                    }
                    else if(t[i+1][j]==0){
                        t[i+1][j]=1;
                        wsp_i1=i+1;
                    }
                    else if(t[i+1][j]==3){
                            kierunek=72;
                            if(wsp_i1==0){
                                przegrana=true;
                            }
                            else if(t[i-1][j]==0){
                                t[i-1][j]=1;
                                wsp_i1=i-1;
                            }
                            else if(t[i-1][j]<1000) przegrana=true;
                            else{
                                wynik++;
                                t[i-1][j]=1;
                                wsp_i1=i-1;
                                while(true){
                                    wsp_i_jab=rand()%wymiar;
                                    wsp_j_jab=rand()%wymiar;
                                    if(t[wsp_i_jab][wsp_j_jab]==0){
                                        t[wsp_i_jab][wsp_j_jab]=1111;
                                        break;
                                    }
                                }
                                czy_jablko=true;
                              }
                         }
                         else if(t[i+1][j]<1000) przegrana=true;
                              else{
                                wynik++;
                                t[i+1][j]=1;
                                wsp_i1=i+1;
                                while(true){
                                    wsp_i_jab=rand()%wymiar;
                                    wsp_j_jab=rand()%wymiar;
                                    if(t[wsp_i_jab][wsp_j_jab]==0){
                                        t[wsp_i_jab][wsp_j_jab]=1111;
                                        break;
                                    }
                                }
                                czy_jablko=true;
                              }
                }
    }
    if(!czy_jablko){
        t[wsp_iost][wsp_jost]=0;
        if(wsp_iost!=0 && t[wsp_iost-1][wsp_jost]==wynik) wsp_iost--;
        else if(wsp_iost!=wymiar-1 && t[wsp_iost+1][wsp_jost]==wynik) wsp_iost++;
        else if(wsp_jost!=0 && t[wsp_iost][wsp_jost-1]==wynik) wsp_jost--;
        else if(wsp_jost!=wymiar-1 && t[wsp_iost][wsp_jost+1]==wynik) wsp_jost++;
    }
    if(wynik==koniec+3) wygrana=true;
    if(przegrana || wygrana) break;
    cout<<"Twoj aktualny wynik: "<<wynik-3<<"      Cel: "<<koniec<<endl;
    for(int i=0;i<wymiar+2;i++) cout<<"+";
    cout<<endl;
    for(int i=0;i<wymiar;i++){
        cout<<"+";
        for(int j=0;j<wymiar;j++){
            if(t[i][j]>1000) cout<<"$";
            else if(t[i][j]!=0) cout<<"#";
            else cout<<" ";
        }
        cout<<"+";
        cout<<endl;
    }
    for(int i=0;i<wymiar+2;i++) cout<<"+";
    cout<<endl;
    cout<<"Wspolrzedne glowy Jima: x: ";
    if(wsp_j1<10) cout<<0<<wsp_j1;
    else cout<<wsp_j1;
    cout<<"  y: ";
    if(wsp_i1<10) cout<<0<<wsp_i1;
    else cout<<wsp_i1;
    Sleep(100);
}
ShowCursor();
system("cls");
cout<<"Uzyskany wynik: "<<wynik-3<<"/"<<koniec<<endl;
if(przegrana) cout<<"Przegrales!\nPrzez Ciebie Jim bedzie glodowac!\nNie mozemy tego tak zostawic!\nSprobuj jeszcze raz!\n";
if(wygrana) cout<<"Wygrales!\nGratulacje!!!\nDzieki Tobie, Jim jest najedzony i wdzieczny!\n\n";
cout<<"Wcisnij enter, aby wyjsc.";
while(true) if(_getch()==13) break;
}
