#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int N = 1e2 + 10;
int T[ N ];
bool P[ N ];
int Wb[ N ];


void quicksort(int s, int e){
	if(e-s != 0){
		int pivot = e;
		int j = s-1;
		for(int i=s; i<=e; i++){
			if(T[i] > T[pivot]) continue;
			if(T[i] <= T[pivot]){
				j++;
				swap(T[i], T[j]);
				if(i == pivot) pivot = j;
			}
		}
		if(pivot != s)quicksort(s, pivot-1);
		if(pivot != e)quicksort(pivot+1, e);
	}

}



int liczba_pierwsza(int n){
	for(int i=2; i*i < n; i++){
		for(int j = 2*i; j <= n; j= j + i){
			P[j] = 1;
		}
	}
	int count=0;
	for(int i=2; i <= n; i++){
		if(P[i] == 0){
			Wb[count] = i;
			count++;
		}
	}
	return count;
}

string cezar(int p, string t){
	for(int i =0; i <t.length(); i++){
		int c = char(t[i]);
		c += p;
		while(c > 90) c -= 26;
		while(c < 65) c += 26;
		t[i] = char(c);
	}
	return t;
}






int main(){
	ifstream plik1("dane-challenge.txt");
	if(!plik1){
		cout << "blad wczytywania";
	}
	for(int i=1; i <= 100; i++){
		plik1 >> T[i];
	}
	for(int i=1; i <= 100; i++){
		cout << T[i] << " ";
	}
	quicksort(1, 100);
	cout << endl;
	cout << endl;
	for(int i=1; i <= 100; i++){
		cout << T[i] << " ";
	}

	cout << endl;
	cout << endl;

	int n = T[100];
	int ile = liczba_pierwsza(n);
	for(int i=0; i < ile; i++){
		cout << Wb[i] << " ";
		

	}
	cout << endl;
	cout << ile;
	cout << endl;
	for(int i=65; i <=90; i++){
		char c = i;
		cout << c << " ";
	}

	ofstream plik2("wynika.txt");
	for(int i=1; i <=100; i++){
		plik2 << T[i] << " ";
	}
	plik2.close();

	cout << endl;
	cout << endl;
	cout << endl;

	cout << "elo";
	cout << endl;
	cout << cezar(1, "ALEK");





}