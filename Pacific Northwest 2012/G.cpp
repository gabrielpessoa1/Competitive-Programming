#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
int dp[64][3][2];
int mark[64][3][2];
int dig[64];
 
int t;
 
int solve(int p = 63, int md = 0, int bounded = 1) {
	if(p == -1) return (md % 3) == 0;
	int &ans = dp[p][md][bounded];
	if(mark[p][md][bounded] == t) return ans;
	mark[p][md][bounded] = t;
	if(bounded && dig[p]) {
		ans = solve(p-1, md, 0) + solve(p-1, (md+1)%3, 1);
	} else if(bounded && !dig[p]) {
		ans = solve(p-1, md, 1);
	} else {
		ans = solve(p-1, md, 0) + solve(p-1, (md+1)%3, 0);
	}
	return ans;
}
 
main() {
	int n;
	while(cin >> n) {
		t++;
		for(int i = 0; i < 64; i++) {
			dig[i] = n & (1ll << i);
		}
		cout << "Day " << n << ": Level = " << solve()-1 << '\n';
	}
}