#include <bits/stdc++.h>
using namespace std;

const int N = 10e5;
int tab[ N ];

void qsort(int l, int r)
{
    if(l<r){
        int m = l;
        for(int i= l+1; i<=r; i++)
        {
            if(tab[i]< tab[l])
            {
                swap(tab[++m], tab[i]);

            }
        }
        swap(tab[l], tab[m]);
        qsort(l, m-1);
        qsort(m+1, r);
    }
}


int main()
{
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> tab[i];
    }
    qsort(0, n-1);
    for(int i=0; i<n; i++)
    {
        cout << tab[i] << " ";
    }
    
    
}