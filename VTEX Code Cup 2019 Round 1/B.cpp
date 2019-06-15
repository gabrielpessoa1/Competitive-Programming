// VTEX Code Cup 2019
// B - Con Master
// https://vtexcc19.kattis.com/problems/vtexcc19.conmaster

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector<int> vi;

const int ms = 1e6+5;
const int mod = 1e9+7;

ll dp[ms];

ll k, a, b, c;

ll get(ll i, ll j) {
  return c -a*(j-1) + dp[j-1] -b*(i-j) + dp[i-j];
}

main() {
  cin >> k >> a >> b >> c;
  dp[0] = 0;
  for(int i = 1; i <= k; i++) {
    ll A = 1, B = i;
    while(B - A > 4) {  
      ll m1 = (A + B) / 2;
      ll m2 = (A + B) / 2 + 1;
      if(get(i, m1) < get(i, m2))
        A = m1;
      else
        B = m2;
    }
    dp[i] = get(i, A);
    for(int j = A+1; j <= B; j++) {
      dp[i] = max(dp[i], get(i, j));
    }
  }
  if(dp[k] == 0) {
    cout << "0/1\n";
  } else {
    ll gc = __gcd(abs(dp[k]), k);
    cout << dp[k]/gc << "/" << k/gc << "\n";
  }
}