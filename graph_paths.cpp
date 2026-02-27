#include <bits/stdc++.h>
using namespace std;

// N - wierzcholki
// M - krawedzie

const int Q = 1e5 + 10;

string t[ Q + 2];


int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=1; i < Q; i++)
    {
    	t[i] = to_string(i);
    }
    int N, M;
    cin >> N >> M;


    for(int i=0; i < M; i++)
    {
    	int p1, p2;
    	cin >> p1 >> p2;
    	string d1 = t[p1];
    	string d2 = t[p2];
    	if(d2.length() < d1.length() + 1) t[p2] = t[p1] + to_string(p2);
    	
    }
    string top = "";
    for(int i=1; i <= N; i++)
    {
    	string przyklad = t[i];
    	if(top.length() < przyklad.length()) top = przyklad;

    }
    cout << int(top.length() - 1);




}

/*
		cout << "[";
    	for(int i=1; i <= N; i++){
    		
    		cout << "``" << i << "," << t[i] << "\\";
    	}
    	cout << "]" << endl;
    	*/