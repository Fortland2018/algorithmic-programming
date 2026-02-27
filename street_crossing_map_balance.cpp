#include <bits/stdc++.h>

using namespace std;

map<int, int>mapa;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    int n, m, p, t, a, b, res = 0;
    
    cin >> n >> m >> p >> t;
    res = t + p;
    while(p--)
    {
        cin >> a >> b;
        a = -a;
        b = -b;
        
        mapa[a - b]++;
    }

    while(t--)
    {
        cin >> a >> b;
        
        if(mapa[b - a] == 1) res++;
        else if(mapa[b - a] > 1) res--;
    }
     
    cout << res;

    return 0;
    
	
    
}