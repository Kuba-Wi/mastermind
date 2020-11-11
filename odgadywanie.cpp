#include <iostream>
#include <cstdlib>

using namespace std;
int czerwone[9];
int biale[9];
char odgaduje[9][4];
char legenda[8];
char proba[4];
int nr_wiersza=2;
void poczatek()
{
    cout<<"Program odgaduje haslo w grze mastermind.\n";
    cout<<"Po kazdym ruchu wpisz ilosc czerwonych i bialych elementow.\n\n";
}
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
}
void fill_legenda()
{
    legenda[0]='c';
    legenda[1]='r';
    legenda[2]='n';
    legenda[3]='Z';
    legenda[4]='s';
    legenda[5]='b';
    legenda[6]='p';
    legenda[7]='z';
}
void pierwsze_dwa()
{
    odgaduje[0][0]='c';
    odgaduje[0][1]='r';
    odgaduje[0][2]='n';
    odgaduje[0][3]='Z';

    odgaduje[1][0]='s';
    odgaduje[1][1]='b';
    odgaduje[1][2]='p';
    odgaduje[1][3]='z';

    for(int k=0;k<=1;k++)
    {
        cout<<k+1<<".\n";
        for(int i=0;i<4;i++)
            cout<<odgaduje[k][i];
        cout<<"\nCzerwone: ";
        cin>>czerwone[k];
        cout<<"Biale: ";
        cin>>biale[k];
    }
}
int sprawdzam(char proba[])
{
    int wiersze_poprawnie=0;

    int czerwone_sprawdzam[9]={0};
    int biale_sprawdzam[9]={0};

    for(int k=0;k<nr_wiersza;k++)
    {
        int bialo[4]={0};
        int blokuj_haslo[4]={0}; //niezbędne gdy hasło zawiera kilka elementów w tym samym kolorze

        for(int j=0;j<4;j++)
            if(proba[j]==odgaduje[k][j])
            {
            czerwone_sprawdzam[k]++;
            bialo[j]=1;
            blokuj_haslo[j]=1;
            }

        for(int j=0;j<4;j++)
            for(int l=0;l<4;l++)
                if(bialo[j]==0 and blokuj_haslo[l]==0 and proba[l]==odgaduje[k][j])
                {
                    bialo[j]=1;
                    blokuj_haslo[l]=1;
                    biale_sprawdzam[k]++;
                }
        if(biale_sprawdzam[k]==biale[k] and czerwone_sprawdzam[k]==czerwone[k])
            wiersze_poprawnie++;
    }
    if(wiersze_poprawnie==nr_wiersza)
        return 1;
    else
        return 0;
}
void sprawdzam_all()
{
    int wyjscie=0;
    for(int a=0;a<8;a++)
    {
        if(wyjscie==1)
            break;
        proba[0]=legenda[a];
        for(int b=0;b<8;b++)
        {
            if(wyjscie==1)
                break;
            proba[1]=legenda[b];
            for(int c=0;c<8;c++)
            {
                if(wyjscie==1)
                    break;
                proba[2]=legenda[c];
                for(int d=0;d<8;d++)
                {
                    if(wyjscie==1)
                        break;
                    proba[3]=legenda[d];
                    if(sprawdzam(proba)==1)
                    {
                        for(int k=0;k<4;k++)
                            odgaduje[nr_wiersza][k]=proba[k];
                        wyjscie=1;
                        break;
                    }
                }
            }
        }
    }
}
void koniec()
{
    cout<<"Haslo to:\n";
    for(int k=0;k<4;k++)
        cout<<odgaduje[nr_wiersza][k];
}

void pokaz()
{
    for(;nr_wiersza<9;nr_wiersza++)
    {
        sprawdzam_all();
        cout<<nr_wiersza+1<<".\n";
        for(int k=0;k<4;k++)
            cout<<odgaduje[nr_wiersza][k];
        cout<<"\nCzerwone: ";
        cin>>czerwone[nr_wiersza];
        if(czerwone[nr_wiersza]==4)
           {
               koniec();
               break;
           }
        cout<<"Biale: ";
        cin>>biale[nr_wiersza];
    }

}

int main()
{
    poczatek();
    Legenda();
    fill_legenda();
    pierwsze_dwa();
    pokaz();

    cout<<endl;
    system("pause");

    return 0;
}
