#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int x;
    cin >> x;
    int t[x*2];
    for(int i=x; i < (2*x); i++)
    {
        cin >> t[i];
        int m = i;
        while(m > 0)
        {
            m = m/2;
            t[m] = t[m*2] + t[m*2+1];
        }
    }
    
    cout << endl;
    cout << "Co chcesz zrobic?" << endl;
    cout << "wlozenie liczby = 1, suma  przedzialu = 2" << endl;
    int wybor;
    cin >> wybor;
    if(wybor == 1)
    {
        cout << "podaj wartosc oraz index(zaczynajac od 0)";
        int index;
        int a;
        cin >> a >> index;
        index += x;
        t[index] += a;
        while(index > 0)
        {
            index = index/2;
            t[index] = t[index*2] + t[index*2+1];
        }
    }
    cout << endl;
    
    
    if(wybor == 2)
    {
        int a1, b1, suma =0;
        cin >> a1 >> b1;
        a1 -= 1 + x;
        b1 += 1 + x;
        while(a1/2 != b1/2)
        {
            if(a1%2 == 0) suma += t[a1+1];
            if(b1%2 == 1) suma += t[b1 - 1];
            a1 = a1/2;
            b1 = b1/2;
        }
        cout << suma;
    }
    
    cout << endl;
    for(int i=1; i < 2*x; i++)
    {
        cout << t[i] << "[" << i << "]/";
    }
    return 0;
    
	
    
}
/*
             1
       2           3
    4    5     6     7
   8 9 10 11 12 13 14 15 
*/