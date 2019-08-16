#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e6+5;
const int mod = 998244353;

int dp[505][505];
int c[ms];
vector<int> v[ms];
int m, t[2 * ms];

void build() {
  for(int i = m; i < m + m; i++) {
    t[i] = c[i-m+1];
  }
  for(int i = m - 1; i > 0; --i) {
    t[i] = min(t[i<<1], t[i<<1|1]); // Merge
  }
}

int query(int l, int r) {
  int res = 1000;
  l--; r--;
  for(l += m, r += m+1; l < r; l >>= 1, r >>= 1) {
    if(l&1) res = min(res, t[l++]); // Merge
    if(r&1) res = min(res, t[--r]); // Merge
  }
  return res;
}

int n;
vector<pair<int, int>> mid[ms];

int solve(int x, int y) {
  //cout << "chamado: " << x << ' ' << y << endl;
  if(~dp[x][y]) return dp[x][y];
  int &ans = dp[x][y] = 0;
  ans = 1;
  int a = v[x][0], b = v[y][v[y].size() - 1]; 
  int lo = query(a, b);
  if(v[lo][0] < a || v[lo][v[lo].size()-1] > b) return 0;
  for(auto p : mid[lo]) {
    //cout << "Mid call de " << x << ' ' << y << ' ' << lo << endl;
    ans = ans * solve(p.first, p.second) % mod;
  }
  if(x == y) {
    return ans;
  }
  //cout << "Big call de " << x << ' ' << y << ' ' << lo << endl;
  int ansLeft = lo == x ? 1 : solve(x, c[v[lo][0]-1]) * 2 % mod;
  //cout << "Big call 2 de " << x << ' ' << y << ' ' << lo << endl;
  int ansRight = lo == y ? 1 : solve(c[v[lo][v[lo].size() - 1]+1], y) * 2 % mod;
  for(int i = 1; i <= n; i++) {
    if(v[i][0] < v[lo][0] && v[i][0] > a) {
      //cout << "Left call de " << x << ' ' << y << ' ' << lo << ' ' << i << endl;
      int c1 = c[v[lo][0]-1];
      int c2 = c[v[i][0]-1];
      if(v[c1][v[c1].size()-1] == v[lo][0]-1 && v[c2][v[c2].size()-1] == v[i][0] -1)
        ansLeft = (ansLeft + solve(i, c1) * solve(x, c2)) % mod;
    } else if(v[i][0] > v[lo][v[lo].size()-1] && v[i][v[i].size()-1] < b) {
      //cout << "Right call de " << x << ' ' << y << ' ' << lo << ' ' << i << endl;
      int c1 = c[v[lo][v[lo].size()-1]+1];
      int c2 = c[v[i][v[i].size()-1]+1];
      if(v[c1][0] == v[lo][v[lo].size()-1]+1 && v[c2][0] == v[i][v[i].size()-1]+1)
        ansRight = (ansRight + solve(c1, i) * solve(c2, y)) % mod;
    }
  }
//cout << ansLeft << ' ' << ansRight << ' ' << a << ' ' << b << endl;
  return ans = ans * ansLeft % mod * ansRight % mod;
}


main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    cin >> c[i];
    v[c[i]].emplace_back(i);
  }
  build();
  for(int i = 1; i <= n; i++) {
    if(query(v[i][0], v[i][v[i].size()-1]) < i) {
      //cout << i << ' ' << query(v[i][0], v[i][v[i].size()-1]) << endl;
      cout << 0 << '\n';
      return 0;
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < v[i].size() -1; j++) {
      if(v[i][j] + 1 != v[i][j+1]) {
        mid[i].emplace_back(c[v[i][j]+1], c[v[i][j+1]-1]);
      }
    }
  }
  cout << solve(c[1], c[m]) << '\n';
}