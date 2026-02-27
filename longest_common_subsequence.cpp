#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
string dp[2][N]; // dp[i][j]
string up[N];
string normal[N];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string tymek1, tymek2, tymek3, tymek4;
    string p, d;
    cin >> p >> d;
    int dl_1, dl_2;
    dl_1 = p.length();
    dl_2 = d.length();
    // pierwszy wiersz
    for(int j=0; j < dl_1; ++j)
    {
        if (j == 0) {
                up[j] = (p[j] == d[0]) ? string(1, p[j]) : "";
            }
            else {
                up[j] = (p[j] == d[0]) ? string(1, p[j]) : up[j - 1];
            }
    }
    // reszta
    if(dl_2 > 1){
    for (int i = 1; i < dl_2; i++) {
        for (int j = 0; j < dl_1; ++j) {
            
            
            
            if (j == 0) {
                normal[j] = (p[j] == d[i]) ? string(1, p[j]) : up[j];
            }
            else if (p[j] == d[i]) {
                normal[j] = up[j - 1] + p[j];
            }
            //
            
            
            else {
                tymek1 = up[j];
                tymek2 = normal[j-1];
                tymek4 = up[j-1];
                if(tymek1.length() >= tymek4.length() && tymek1.length() >= tymek2.length()){
                    tymek3 = tymek1;
                }
                if(tymek2.length() >= tymek4.length() && tymek2.length() >= tymek1.length()){
                    tymek3 = tymek2;
                }
                if(tymek4.length() >= tymek1.length() && tymek4.length() >= tymek2.length()){
                    tymek3 = tymek4;
                }
                normal[j] = tymek3;
            }
        }
        swap(up, normal);
    }
    }
    string maxS = "";
    for(int j=0; j < dl_1; ++j){
        string chw = up[j];
        if(chw.length() > maxS.length()) maxS = chw;
    }
    for(int j=0; j < dl_1; ++j){
        string chw = normal[j];
        if(chw.length() > maxS.length()) maxS = chw;
    }
    cout << maxS;
    return 0;
}
