#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = (long long) (1e15) +37;

string s[3];

void get(int lo, int hi, int cur, vector<int> &ans) {
  if(lo > hi) ans.push_back(cur);
  else {
    for(int i = 0; i < 3; i++) {
      get(lo, hi-1, (cur * 127 + s[i][hi]) % mod, ans);
    }
  }
}

int solve(int n) {
  for(int i = 0; i < 3; i++) {
    cin >> s[i];
    reverse(s[i].begin(), s[i].end());
  }
  vector<int> ans1, ans2;
  if(n <= 14) {
    get(0, n-1, 0, ans1);
    sort(ans1.begin(), ans1.end());
    return ans1[0];  
  } else {
    get(0, 13, 0, ans1);
    get(14, n-1, 0, ans2);
    sort(ans1.begin(), ans1.end());
    int ans = mod - 1;
    for(int x : ans2) {
      for(int tmp = 0; tmp < 14; tmp++) {
        x = (x * 127) % mod;
      }
      ans = min(ans, (x + ans1[0]) % mod);
      auto k = lower_bound(ans1.begin(), ans1.end(), mod-x);
      if(k != ans1.end()) {
        ans = min(ans, (x + (*k)) % mod);
      }
    }
    return ans;
  }
}

main() {
  int a, b;
  cin >> a >> b;
  int sa = solve(a);
  int sb = solve(b);
  if(sa < sb) cout << "Owls\n";
  else if(sa > sb) cout << "Goats\n";
  else cout << "Tie\n";
}