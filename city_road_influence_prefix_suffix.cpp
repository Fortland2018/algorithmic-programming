#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int t[ N ];
int w[ N ];

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    int n;
    int ciag = 1; // index ostatniej przerwy
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> t[i];
    }
    for(int i = n-2; i >=0; i--)
    {
        if(t[i] == 0 || t[i] == 2)
        {
            w[i] += ciag;
            ciag++;
            
        }
        else
        {
            ciag = 1;
            
        }
    }
    ciag = 1;
    for(int i = 0; i < n-1; i++)
    {
       if(t[i] == 1 || t[i] == 2)
       {
            w[i+1] += ciag;
            ciag++;
            
       }
       else{
        ciag = 1;
        
       }
    }
    
    for(int i = 0; i < n; i++)
    {
        cout << w[i] << " ";
    }
}

/*
if(t[i] == 1 || t[i] == 2)
        {
            int r = i+1;
            while(r <= ciag){
                w[r]++;
                r++;
                
            }
            cout << "/";
        }
        else{
            ciag = i - 1;
            cout << "]";
        }
 if(t[i] == 0 || t[i] == 2)
        {
            int r = i;
            while(r >= ciag){
                w[r]++;
                r--;
                cout << "/";
            }
        }
        else{
            ciag = i + 1;
            cout << "]";
        }
*/