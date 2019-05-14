// May Challenge 2019
// MATCHS - Matches
// https://www.codechef.com/MAY19B/problems/MATCHS

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve(ll n, ll m) {
	if(m > n) return solve(m, n);
	if(m == 0) return 0;
	if(n/m == 1) return !solve(m, n%m);
	return 1;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, m;
		cin >> n >> m;
		if(solve(n, m)) cout << "Ari\n";
		else cout << "Rich\n";
	}
}