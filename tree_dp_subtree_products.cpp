#include <bits/stdc++.h>
using namespace std;

const int N = 1e6, MOD = 1e9 + 7;
vector<int> G[ N + 10 ]; // graf
long long poj[ N ]; // zliczanie do wyniku
long long wynik = 1;
bool szyn[ N ]; // sprawdza czy to lisc
int mnozenie[ N ];




void dfs(int k, int o)
{
    mnozenie[k] = 1;
    szyn[k] = 0;
    poj[k] = 1;
    for(int i : G[k])
    {
        if(i != o)
        { 
            dfs(i, k);
            if(szyn[k] == 1)
            {
                poj[k] = ((poj[k])%MOD * ((mnozenie[k] + 1))%MOD)%MOD;
                mnozenie[k]++;
                
            }
            
            szyn[k] = 1;
        }
    }
    
    

}


main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    for(int i=0; i< (n-1); i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    dfs(1, 1);
    for(int i =1; i<= n; i++)
    {
        wynik = ((wynik)%MOD * (poj[i])%MOD)%MOD;
        
    }
    
    cout << wynik%MOD <<  endl;
    
    
    
   

}