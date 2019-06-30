#include <bits/stdc++.h>
using namespace std;
 
int n, k, s;
int dp[22][11][200];
 
main() {
	while(cin >> n >> k >> s, n || k || s) {
		dp[0][0][0] = 1;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j <= k; j++) {
				for(int x = 0; x <= s; x++) {
					dp[i][j][x] = dp[i-1][j][x];
					if(i <= x && j > 0) dp[i][j][x] += dp[i-1][j-1][x-i];
					//cout << i << ' ' << j <<  ' ' << x << ' ' << dp[i][j][x] << endl;
				}
			}
		}
		cout << dp[n][k][s] << endl;
	}
}