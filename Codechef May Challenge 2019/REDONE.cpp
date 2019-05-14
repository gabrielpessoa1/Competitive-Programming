// May Challenge 2019
// REDONE - Reduce to One
// https://www.codechef.com/MAY19B/problems/REDONE

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 1e6+5;
const ll mod = 1e9+7;

ll ans[ms];

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
	ans[0] = 0;
  for(int i = 1; i < ms; i++) {
    ans[i] = (i + ans[i-1] + i * ans[i-1]) % mod;
  }
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    cout << ans[n] << '\n';
  }
}