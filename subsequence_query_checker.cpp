#include <bits/stdc++.h>

using namespace std;

const int M = 1e6 + 10;
int TAB[ M ];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x; // dlugosc ciagu
    cin >> x;
    for(int i = 0; i < x ; i++)
    {
        cin >> TAB[i];
    }
    int m, w, koniec = 0, licznik=0;
    cin >> m;
    bool t[m];
    for(int i=0; i< m; i++)
    {
        int d;
        cin >> d;
        koniec = 0;
        for(int j = 0; j < d; j++)
        {
            cin >> w;
            
            for(int q = koniec; q < x; q++)
            {
                if(TAB[q] == w) 
                {
                    koniec = q + 1;
                    licznik++;
                    break;
                }
            }
            if(licznik == d) break;
        }
        if(licznik == d) t[i] = true;
        else t[i] = false;
        licznik = 0;
    }
    for(int i=0; i < m; i++)
    {
        if(t[i] == true) cout << "TAK";
        else cout << "NIE";
    }
}
