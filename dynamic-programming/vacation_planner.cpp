#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int dp[3][N]; // 0 - a, 1 - b, 2 - c

int main()
{
	int n;
	cin >> n;
	
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[2][0] = 0;
	for (int i=1;i <= n;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		// a
		dp[0][i] += max(dp[1][i-1], dp[2][i-1]) + a;
		
		// b
		dp[1][i] += max(dp[0][i-1], dp[2][i-1]) + b;
		
		// c
		dp[2][i] += max(dp[1][i-1], dp[0][i-1]) + c;
		
	}
	int wynik = max(dp[0][n], max(dp[1][n], dp[2][n]));
	cout << wynik;
}