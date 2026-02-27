#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int t1[ N ], t2[ N ];


void Shaker1(int n, int* t1){
    int left=1, right = n-1, k=n-1;
    do{
        for(int j= right; j>=left; j--)
        {
            if(t1[j]<t1[j-1])
            {
                swap(t1[j], t1[j-1]);
                k = j;
                
            }
        }
        left = k + 1;

        
        for(int j= left; j<=right; j++)
        {
            if(t1[j]<t1[j-1])
            {
                swap(t1[j], t1[j-1]);
                k = j;
            }
        } 
        right = k - 1; 
       
    }while(left<=right);
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int wynik = 0;
    priority_queue<int> kolejka;
    priority_queue<int>do_poprawy;
    stack<int>trzeba_zmienic;
    
    bool zgodnosc = true;
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        cin >> t1[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> t2[i];
    }
    Shaker1(n, t1);
    Shaker1(n, t2);
    
    int r=0;
    for(int i=0; i< n; i++)
    {
        while(t2[r]<=t1[i])
        {
            kolejka.push(t2[r]);
            r++;
        }
        
        if(!kolejka.empty())
        {
            if(t1[i]-kolejka.top() >= 0)
            {
                do_poprawy.push(t1[i]-kolejka.top());
            }
            kolejka.pop();
            
        }
        else{
            
            trzeba_zmienic.push(t1[i]);
        }
        
        
        
    }
   
    
    if(trzeba_zmienic.size()>k) zgodnosc = 0;
    k = k-trzeba_zmienic.size();
    
    
    if(zgodnosc == 1)
    {
        while(!do_poprawy.empty() && k > 0)
        {
            wynik -= do_poprawy.top();
            do_poprawy.pop();
            k--;
            
        }
    }

    for(int i=0; i < n; i++)
    {
        wynik += t1[i];
    }
    
    
    for(int j=0; j < trzeba_zmienic.size(); j++)
    {
        wynik -= trzeba_zmienic.top();
        trzeba_zmienic.pop();
        
        wynik += kolejka.top();
        kolejka.pop();
        
    }
    
    if(zgodnosc == 1){
        cout << wynik; 
    }
    else{
        cout << "NIE";
    }
   
    
    
    
    

}
