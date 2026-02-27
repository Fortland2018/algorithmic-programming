#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<bool> V;
stack<int> S;
queue<int> Odp;
// vector<int> col;

void dfs(int c){
    V[c] = true;
    S.push(c);
    while(!S.empty()){
        int top = S.top();
        Odp.push(top);
        // cout << "<" << top << ">" << endl;
        S.pop();
        for(int i : G[top]){
            if(!V[i]){
                S.push(i);
                V[i] = true;
            }
        }
    }
}

// void Dfs(int c, int color){
//     V[c] = true;
//     cout << c << endl;
//     for(int i : G[c]){
//         col[i] = color;
//         if(!V[i]){
//             V[i] = true;
//             Dfs(i, color);
//         }
//     }
// }
int d = 0;
bool Dfs(int c, int color){
    V[c] = true;
    cout << c << endl;
    if(G[c].empty()){
        return false;
    }
    for(int i : G[c]){

        // col[i] = color;
        if(c != color && color == i){
            d = 1;
            return true;
        }
        if(!V[i]){
            if(Dfs(i, color) == false) continue;
            else return true;
        }
    }
    if(c == color && d != 1) return false; 
    return false; 
}

bool wynik[20];

int main(){
    int w, k;
    cin >> w >> k;
    G.resize(w);
    for(int i=0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    
    for(int i =0; i < w; i++){
        // col.resize(w, -1);
        // col[i] = i;
        d = 0;
        wynik[i] = Dfs(i, i);
        // cout << '\n';
        // cout << "koniec";
        // cout << '\n';
    }
    //dfs(0);
    // while(!Odp.empty()){
    //     cout  << Odp.front() << " ";
    //     Odp.pop();
    // }

}
