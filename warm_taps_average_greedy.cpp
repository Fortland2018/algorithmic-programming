#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int tab[ N ];




int main()
{
    int n, t, wynik=0, wyniczek=0; // n to liczba kranow, t to temp min, wynik to suma poczatkowa temp, wyniczek to liczba zgaszonych kranow
    cin >> n >> t;
    int kurewki=0, g; // kurewki to liczba dodatnich kranow, g to gowno
    for(int i=0; i< n; i++)
    {
        cin >> g;
        if(g>=0){
            tab[i] = g; 
            wynik += tab[i];
            kurewki++;
        } 
    }
    int r=0;
    sort(tab, tab + kurewki);
    while(wynik<t*kurewki && kurewki>0){
        kurewki--;
        wyniczek++;
        wynik -= tab[r];
        tab[r] = 0;
    }
    if(kurewki<=0) cout << "NIE";
    else{
        cout << wyniczek;
    }
    

    
    
    
    
    
}