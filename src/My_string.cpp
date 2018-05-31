#include "My_string.h"

My_string :: My_string()
{
    tab = 0;
    n=1;
}

My_string :: My_string(char *chaine)
{
    n = strlen(chaine);
    tab = new char[n];
    tab = chaine;
    majstat();
}

My_string :: My_string(char c, int chiffre)
{
    int i;
    n = chiffre;
    tab = new char[n];
    for(i=0; i<n; i++)
        tab[i] = c;
    majstat();
}

My_string :: My_string(const My_string& copie)
{
    tab = copie.tab;
    n=copie.n;
    for(int i ; i<n; i++)
    {
        stat[i] = copie.stat[i];
    }
    majstat();
}

My_string :: ~My_string()
{
}

////////////////
////A FIXER/////
////////////////
My_string& My_string :: operator+( const My_string& p)
{
    int j=0;
    int taille = strlen(tab) + strlen(p.tab);
    char *conta = new char [taille];

    for(int i=0; i<n; i++)
    {
        conta[j] = tab[i];
        j++;
    }
    for(int i=0; i<strlen(p.tab); i++)
    {
        conta[j] = p.tab[i];
        j++;
    }
    conta[j]='\0';
    delete tab;
    n = taille;
    tab = new char [n];
    tab = conta;
    majstat();
    return *this;

}

My_string& My_string::operator=(const My_string &chaine)
{
    int i;
    delete tab;
    n=chaine.n;
    tab = new char[chaine.n];

    for(i=0; i<n; i++)
        tab[i] = chaine.tab[i];

    majstat();
    return *this;
}


void My_string :: affiche()
{
    int i;
    for(i=0; i<n; i++)
        cout<<tab[i];
    cout<<""<<endl;
    char carac;
    for(i=0;i<26;i++)
    {
        carac=i+65;
        if(stat[i]>0)
            cout<<carac<<" ";
    }
    cout<<""<<endl;

    for(i=0;i<26;i++)
    {
        if(stat[i]>0)
            cout<<stat[i]<<" ";
    }
    cout<<""<<endl;
    cout<<""<<endl;

}

void My_string :: majstat()
{
    int i;
    char car;
    spe = 0;

    for(i=0; i<26; i++)
        stat[i]=0;

    for(i=0; i<n; i++)
    {
        car = toupper(tab[i]);
        if((car>='A')&&(car<='Z'))
            stat[car-'A']++;
        else
            spe++;
    }

}

void My_string :: supprime(char supr)
{
    int i,j,cpt;
    char *dest;

    for(i=0, cpt=0; i<n; i++)
    {
        if(tab[i]==supr)
            cpt++;
    }

    dest = new char[n-cpt+1];

    for(i=0, j=0; i<=n; i++)
    {
        if(tab[i]!=supr)
            dest[j++]=tab[i];
    }

    delete tab;
    n = n-cpt+1;
    tab = new char [n];
    tab = dest;
    majstat();
}

void My_string :: concatene(const My_string& p)
{
    int j=0;
    int taille = strlen(tab) + strlen(p.tab);
    char *conta = new char [taille];
cout<<strlen(tab);
    for(int i=0; i<n-1; i++)
    {
        conta[j] = tab[i];
        j++;
    }
    for(int i=0; i<strlen(p.tab); i++)
    {
        conta[j] = p.tab[i];
        j++;
    }
    delete tab;
    n = taille;
    tab = new char [n];
    tab = conta;
    majstat();

}
void My_string :: dedouble(char car)
{
    int nbmeme=0;

    for(int i=0; i<n-1; i++)
    {
        if(tab[i]==car)
            nbmeme++;
    }

    int taille = n+nbmeme+1;
    char *dest = new char[taille];


    int j=0;
    for(int i=0; i<n; i++)
    {
        dest[j]=tab[i];
        if(tab[i]==car)
        {
            j++;
            dest[j]=car;
        }
        j++;
    }
    delete tab;
    n = taille;
    tab = new char [n];
    tab = dest;
    majstat();

}

void My_string :: Set_tab(char *p)
{
    char *cible;
    cible = new char [strlen(p)+1];
    strcpy(cible,p);

    delete tab;
    tab = cible;
    n = strlen(tab);
    majstat();
}
string My_string :: Get_tab()
{
    return tab;
}

ostream& operator<< (ostream& os, const My_string& s)
{
    os<<"chaine = ";
    os<<s.tab<<endl;
    os<<"n = "<<s.n<<endl;
    int i;
    os<<s.tab;
    os<<""<<endl;

    char carac;
    for(i=0;i<26;i++)
    {
        carac=i+65;
        if(s.stat[i]>0)
            os<<carac<<" ";

    }
    os<<""<<endl;

    for(i=0;i<26;i++)
    {
        if(s.stat[i]>0)
            os<<s.stat[i]<<" ";
    }
    os<<""<<endl;
    os<<""<<endl;
    return os;
}
