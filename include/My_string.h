#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
#include <string.h>
using namespace std;

class My_string
{
private:
    char *tab;
    int n;
    int stat[26];
    int spe;
    void majstat();
public:
    My_string();
    My_string(char *);
    My_string(char, int);
    My_string(const My_string&);
    ~My_string();
    My_string& operator=(const My_string&);
    My_string& operator+(const My_string&);
    friend ostream& operator<<(ostream&,const My_string&);
    void Set_tab(char *);
    string Get_tab();
    void affiche();
    void supprime(char);
    void dedouble(char);
    void concatene(const My_string&);
    void maj();

};

#endif // MY_STRING_H
