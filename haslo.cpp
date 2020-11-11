#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int wybor;
int czerwone=0;
int biale=0;
char haslo[4];
char odgaduje[4];
void Legenda()
{
    cout<<"Legenda:\n";
    cout<<"c-czerwony"<<endl;
    cout<<"r-rozowy"<<endl;
    cout<<"n-niebieski"<<endl;
    cout<<"Z-zolty"<<endl;
    cout<<"s-szary"<<endl;
    cout<<"b-bialy"<<endl;
    cout<<"p-pomaranczowy"<<endl;
    cout<<"z-zielony"<<endl;
    cout<<endl;

    cout<<"Wcisnij 1, aby wylosowac haslo\n";
    cout<<"Wcisnij 2, aby wpisac haslo\n";
}
void wybierz()
{
    cin>>wybor;
    while(wybor!=1 and wybor!=2)
    {
        cout<<"Wybierz liczbe jeszcze raz\n";
        cin>>wybor;
    }
}
void losuj_haslo()
{
    srand(time(0));
    int liczby[4];
    for(int k=0;k<4;k++)
        liczby[k]=rand()%8;

    for(int k=0;k<4;k++)
    {
        switch(liczby[k])
        {
            case 0: haslo[k]='c';
                    break;
            case 1: haslo[k]='r';
                    break;
            case 2: haslo[k]='n';
                    break;
            case 3: haslo[k]='Z';
                    break;
            case 4: haslo[k]='s';
                    break;
            case 5: haslo[k]='b';
                    break;
            case 6: haslo[k]='p';
                    break;
            case 7: haslo[k]='z';
        }
    }
}
void wpisz_haslo()
{
    cout<<"\nWpisz haslo:\n";
    for(int k=0;k<4;k++)
        cin>>haslo[k];
}
void odgadujacy()
{
    cout<<"\nWpisz probe przeciwnika:\n";
    for(int k=0;k<4;k++)
    cin>>odgaduje[k];
}
void sprawdzam()
{
    czerwone=0;
    biale=0;
    int bialo[4]={0};
    int blokuj_haslo[4]={0}; //niezbêdne gdy has³o zawiera kilka elementów w tym samym kolorze

    for(int k=0;k<4;k++)
       if(haslo[k]==odgaduje[k])
        {
            czerwone++;
            bialo[k]=1;
            blokuj_haslo[k]=1;
        }

    for(int k=0;k<4;k++)
        for(int i=0;i<4;i++)
            if(bialo[k]==0 and blokuj_haslo[i]==0 and haslo[i]==odgaduje[k])
            {
                bialo[k]=1;
                blokuj_haslo[i]=1;
                biale++;
            }
}
void pokaz()
{
    int k=1;
    for(;k<=9;k++)
    {
        cout<<endl<<k<<". ";
        odgadujacy();
        sprawdzam();
        cout<<"Czerwone: ";
        cout<<czerwone<<endl;
        cout<<"Biale: ";
        cout<<biale<<endl;

        if(czerwone==4)
        {
            cout<<endl;
            cout<<"Haslo odgadniete.\n";
            cout<<"Haslo to:\n";
            for(int k=0;k<4;k++)
                cout<<haslo[k]<<" ";
            break;
        }
    }
    if(k>9)
    {
        cout<<endl;
        cout<<"Haslo nieodgadniete.\n";
        cout<<"Haslo to:\n";
            for(int k=0;k<4;k++)
                cout<<haslo[k]<<" ";
    }
}
int main()
{
   Legenda();
   wybierz();
   switch(wybor)
   {
       case 1: losuj_haslo();
                break;
       case 2: wpisz_haslo();
   }
   pokaz();

   cout<<endl;

    return 0;
}
