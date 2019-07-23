#include <bits/stdc++.h>
using namespace std;
 
const int ms = 605;
const int inf = 0x3f3f3f3f;
 
int n, k, p;
vector<pair<int, int>> g[ms];
int b[ms];
int dp[ms][ms];
int going[ms][ms];
 
int solve(int x, int left) {
	if(x == k+1) {
		if(left > 0) return inf;
		else return 0;
	}
	int &ans = dp[x][left];
	if(dp[x][left] != -1) return dp[x][left];
	ans = inf;
	int &ed = going[x][left];
	int sum = 0;
	for(int i = 0; i <= min(left, (int) g[x].size()); i++) {
		if(sum + solve(x+1, left-i) < ans) {
			ans = sum+solve(x+1, left-i);
			ed = i;
		}
		if(i == 0) sum += b[x];
		if(i < g[x].size()) sum += g[x][i].first;
	}
	return ans;
}
 
main() {
	cin.tie(0); ios::sync_with_stdio(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> k >> p;
	for(int i = 1; i <= k; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) {
		int a, c;
		cin >> a >> c;
		g[c].push_back({a, i});
	}
	for(int i = 1; i <= k; i++) sort(g[i].begin(), g[i].end());
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(solve(1, i) <= p) ans = i;
	}
	cout << ans << '\n';
	int k = 1;
	bool good = false;
	while(ans > 0) {
		for(int i = 0; i < going[k][ans]; i++) {
			if(good) cout << ' ';
			cout << g[k][i].second;
			good = true;
		}
		ans -= going[k][ans];
		k++;
	}
	cout << '\n';
}
