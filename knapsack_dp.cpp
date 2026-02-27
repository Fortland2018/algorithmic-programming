#include <bits/stdc++.h>
using namespace std;

const int W_stala = 1e9 + 123;
int tab[ 110 ][ W_stala ];
int value[101][2];

int main(){
	int N, W;
	int w, v;
	cin >> N >> W;
	int value[N + 1][2];
	for (int i = 1; i <= N; ++i)
	{
		cin >> w >> v;
		value[i][0] = w;
		value[i][1] = v;
	}
	for(int i = 1; i <= N+1; i++)
	{
		//cout << '\n';
		for (int j = 0; j <= W; ++j)
		{
			//cout << "[" << tab[i][j] << "] ";
			if(j==0 || tab[i][j] != 0){
				tab[i+1][j] = max(tab[i][j],tab[i+1][j]);
				tab[i+1][j+value[i][0]] = max(tab[i+1][j+value[i][0]], tab[i][j] + value[i][1]);
			}
		}
		//cout << endl;
	}
	int max = 0;
	for(int i = 0; i <= W; i++)
	{
		//cout << "[" << tab[N][i] << " ";
		if(tab[N+1][i] > max) max = tab[1+N][i];
		//cout << max << "]";
	}
	cout << max;
}


// W - pojemnosc 
// 
// 
/*
3 8
3 30
4 50
5 60

*/