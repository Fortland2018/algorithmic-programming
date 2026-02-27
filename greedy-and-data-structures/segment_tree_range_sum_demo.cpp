#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t[16] = {0, 36, 10, 26, 3, 7, 11, 15, 1, 2, 3, 4, 5, 6, 7, 8};
    int a1, b1, suma = 0, x = 8;
    cin >> a1 >> b1; // a1 = 2, b1 = 3
    a1 += (-1 + x); // 
    b1 += 1 + x;
    while(a1/2 != b1/2)
    {
        if(a1%2 == 0) suma += t[a1+1];
        if(b1%2 == 1) suma += t[b1 - 1];
        a1 = a1/2;
        b1 = b1/2;
        cout << suma << "suma|";
    }
    cout << suma;
        
    
    cout << endl;
    for(int i=1; i < 2*x; i++)
    {
        cout << t[i] << "[" << i << "]/";
    }
    return 0;
    
	
    
}