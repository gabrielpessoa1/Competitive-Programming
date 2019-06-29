#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 1e5+5;
 
int bit[ms];
int n;
 
void update(int i) {
	while(i <= n) {
		bit[i]++;
		i += i & -i;
	}
}
 
int query(int i) {
	int ans = 0;
	while(i > 0) {
		ans += bit[i];
		i -= i & -i;
	}
	return ans;
}
 
map<string, int> dic;
 
main() {
	while(cin >> n, n) {
		for(int i = 1; i <= n; i++) bit[i] = 0;
		dic.clear();
		for(int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			dic[s] = i;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			int p = dic[s];
			ans += (i - 1 - query(p));
			update(p);
		}
		cout << ans << '\n';
	}
}