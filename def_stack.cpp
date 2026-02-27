#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G; 


int visited[(int)1e5 * 2 + 10];



void dfs(int k){
	visited[k] = true;
	for(int i=0; i<G[k].size(); i++){
		if(!visited[G[k][i]]) dfs(G[k][i]);
	}
}

bool dfsT(int k, int r, bool root){

	//cout << k << " " << r << " " << root << endl;

	visited[k] = true;
	if(G[k].size() !=2){
		dfs(k);
		return false;} else{
		if(visited[G[k][0]] && visited[G[k][1]] && (G[k][0] == r || G[k][1] == r)) root = true; 
		for(int i=0; i<2; i++){
			if(!visited[G[k][i]]) root = dfsT(G[k][i], r, root);
		}
	} 
	
	if(root == true) return true;
	else return false;
}




int main(){
	int n, m;
	int cc =0;
	cin >> n >> m;
	G.resize(n);
	for(int i=0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for(int i=0; i < n; i++){
		if(!visited[i]) {
			if(dfsT(i, i, false)) cc++;			
		}
	}
	
	cout << cc;

}

