#include <bits/stdc++.h>

using namespace std;

stack<int>S;

int main()
{
    int n, h, b, res = 0;
    cin >> n; // b nie uzywamy

    S.push(0);
    while(n--)
    {
        cin >> b >> h;

        while(S.top() > h) S.pop();

        if(S.top() < h) {
            S.push(h);
            res++;
        }
    }

    cout << res << '\n';

    return 0;
}