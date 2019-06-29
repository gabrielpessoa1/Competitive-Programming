#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 1e6+5;
 
int br[3];
int dp[ms];
 
main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int h, a, b;
	while(cin >> h >> a >> b >> br[0] >> br[1] >> br[2]) {
		for(int i = 0; i <= h; i++) {
			dp[i] = 0;
			for(int j = 0; j < 3; j++) {
				if(br[j] <= i) {
					int l = (a-b)*(i-br[j])/h + b;
					int k = l/br[j];
					dp[i] = max(dp[i], br[j]*br[j]*br[j]*k*k + dp[i-br[j]]);
				}
			}
		}
	
	cout << dp[h] << '\n';
	}	
}