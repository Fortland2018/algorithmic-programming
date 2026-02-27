#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> G[ N + 10 ];
int odwiedzony[ N + 10 ];
int suma[ N + 10 ];

void dfs(int k)
{
    
    for(int i : G[k])
    {
        if(odwiedzony[i]==0)
        {
            
            odwiedzony[i]++; 
            dfs(i);
            suma[k] += suma[i];
            
        }
        
        
    }
}


int main()
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
    odwiedzony[1]++;
    for(int i=1; i<=n; i++)
    {
        suma[i] = 1;
    }
    dfs(1);
    
    
    
    for(int i=1; i<=n; i++)
    {
        cout << suma[i] << " ";
    }

}