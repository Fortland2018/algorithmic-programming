#include <bits/stdc++.h>
using namespace std;

stack<int> t[3]; 
int akcje=0;

void display(int w){
    stack<int> temp0 = t[0];
    stack<int> temp1 = t[1];
    stack<int> temp2 = t[2];
    long unsigned int p[3] = {t[0].size(), t[1].size(), t[2].size()};
    for(long unsigned int i=w; i>0;i--){
        for(int j=0;j<4;j++){
            if(p[j]<i) cout << "0 ";
            else{
                if(j==0) {
                    cout << temp0.top() << " ";
                    temp0.pop();
                }
                if(j==1) {
                    cout << temp1.top() << " ";
                    temp1.pop();
                }
                if(j==2) {
                    cout << temp2.top() << " ";
                    temp2.pop();
                }
            }
            cout << " ";
        }
        cout << endl;
    }
}

void zadanie(int A, int B, int C, int numer){
    /// czy sie wydostanie latwo
    cout << " t";
    if(t[A].top() == numer){
        if(!t[C].empty()){
            if(t[C].top() >= numer){
                t[A].pop();
                t[C].push(numer);  
            }
        }
        else{
            t[A].pop();
            t[C].push(numer);    
        }
        
    }
    if(!t[A].empty()){
        if(t[A].top() != numer) zadanie(A, C , B, numer-1);
    }
    if(t[C].top() != numer){
        zadanie(A, C , B, numer-1);
    }
}

int main()
{
    int wysokosc = 4;
    int w = wysokosc;
    // initial
    for(int i=w;i >0; i--){
        t[0].push(i);
    }
    display(w);
    zadanie(0, 1, 2, w);
    


}
