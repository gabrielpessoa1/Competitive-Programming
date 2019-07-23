#include <bits/stdc++.h>
using namespace std;

const int ms = 4005;

int n, m;
int ds[ms], sz[ms];

void dsBuild() {
  for(int i = 0; i < n; i++) {
    ds[i] = i;
    sz[i] = 1;
  }
}

int dsFind(int i) {
  if(ds[i] != i) ds[i] = dsFind(ds[i]);
  return ds[i];
}

void dsUnion(int a, int b) {
  a = dsFind(a); b = dsFind(b);
  if(sz[a] < sz[b]) swap(a, b);
  if(a != b) sz[a] += sz[b];
  ds[b] = a;
}


vector<int> groups;
int dp[ms][ms];
int use[ms][ms];
int bit[ms];
int myP[ms];

int solve(int p, int ones) {
  if(p == groups.size()) return ones;
  if(~dp[p][ones]) return dp[p][ones];
  int &ans = dp[p][ones] = solve(p+1, ones);
  use[p][ones] = 0;
  int ans2 = solve(p+1, ones + groups[p]);
  if(abs(ans + ans - n) > abs(ans2 + ans2 - n)) {
    ans = ans2;
    use[p][ones] = 1;
  }
  return ans;
}

void recover(int p, int ones) {
  if(p == groups.size()) return;
  bit[p] = use[p][ones];
  if(!use[p][ones]) recover(p+1, ones);
  else recover(p+1, ones+groups[p]);
}

main() {
  int tsz;
  cin >> tsz;
  for(int T = 1; T <= tsz; T++) {
    cout << "Case #" << T << ": ";
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    dsBuild();
    for(int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      for(int i = a; i <= b; i++) {
        int j = b - (i - a);
        dsUnion(i, j);
      }
    }
    groups.clear();
    for(int i = 0; i < n; i++) {
      if(ds[i] == i) {
        myP[i] = groups.size();
        groups.push_back(sz[i]);
      }
    }
    solve(0, 0);
    recover(0, 0);
    for(int i = 0; i < n; i++) {
      cout << bit[myP[dsFind(i)]];
    }
    cout << '\n';
  }
}