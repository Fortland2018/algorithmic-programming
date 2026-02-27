#include <bits/stdc++.h>

using namespace std;

vector<int> G[1000000];
bool visited[1000000];
stack<int> S;

void DFSStack(int father){
    S.push(father);
    while(!S.empty()){
        int naj = S.top();
        S.pop();
        visited[naj] = true;
        for(int i=0; i < G[naj].size(); i++){
            if(!visited[G[naj][i]]) {S.push(G[naj][i]);
            cout << G[naj][i] << " ";
        }
        }
        cout << " ";
    }
    
    
}


int main(){
    int n; //! liczba polaczen
    int w; //! liczba wierzcholkow
    cin >> n;
    for(int i=0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1; i < w; i++)
    {
        DFSStack(i);
    }
}