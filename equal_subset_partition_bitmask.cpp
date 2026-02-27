#include <bits/stdc++.h>
using namespace std;




int main(){
    int n;
    bool wynik =0;
    cin >> n;
    int t[n];
    for(int i=0; i < n; i++)
    {
        cin >> t[i];
    }
    int k = (1<<n);
    int tk[k];
    for(int i=0; i <k; i++)
    {
        tk[i] = i;
    }
    
    for(int i=0; i<k;i++)
    {
        long long int suma1=0, suma2=0;
        for(int l=0; l<n; l++)
        {
            if(((i>>l)&1) == 1) suma1 += t[l];
            else suma2 += t[l];
        }
        if(suma1 == suma2) wynik = 1;
        
    }
    if(wynik) cout << "TAK";
    else cout << "NIE";
    
   
    
}