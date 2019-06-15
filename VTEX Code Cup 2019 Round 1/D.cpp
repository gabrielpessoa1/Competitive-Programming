// VTEX Code Cup 2019
// D - Curupira
// https://vtexcc19.kattis.com/problems/vtexcc19.curupira

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int phi(int n) {
  int ans = n;
  for(int j = 2; j * j <= n; j++) {
    if(n % j == 0) {
      ans -= ans / j;
    }
    while(n % j == 0) n /= j;
  }
  if(n != 1) ans -= ans / n;
  return ans;
}

ll fexp(ll a, ll b, ll mod) {
  ll ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a =  a * a % mod;
    b >>= 1;
  }
  return ans;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int q;
  cin >> q;
  while(q--) {
    int n, k;
    cin >> n >> k;
    n *= 9;
    n /= __gcd(n, k);
    int b = 0;
    while(__gcd(n, 10) != 1) {
      b++;
      n /= __gcd(n, 10);
    }
    int p = phi(n);
    int best = p;
    for(int i = 1; i * i <= p; i++) {
      if(p % i == 0) {
        if(fexp(10, i, n) == 1) best = min(best, i);
        if(fexp(10, p/i, n) == 1) best = min(best, p/i);
      }
    }
    cout << best << ' ' << b << '\n';
  }
}