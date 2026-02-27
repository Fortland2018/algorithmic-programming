#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int length[ N ];
int t[ N ];
int maxi[ N ];

int main(){

	int n, m=0;
	cin >> n;
	for(int i=1; i <= n; i++){
		cin >> t[i];
		maxi[i] = 99;
	}

	for (int k = 1; k <= n; k++) {

		length[k] = 1;

		for (int i = 0; i < k; i++) {

			if (t[i] < t[k]) {

			length[k] = max(length[k],length[i]+1);
			if(maxi[length[k]] > t[i]) maxi[length[k]] = t[i];
			if(m<length[k]) m = length[k];

			}
		}
		if(t[k] < maxi[length[k]])
	}
	cout << m << endl;

	for(int i=0; i <= n; i++){
		cout << length[i] << " ";
	}

}