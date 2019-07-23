#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define double long double
 
const int ms = 1e4+5;
 
vector<pair<int, int>> g[ms];
vector<pair<int, int>> ig[ms];
double dp[ms];
double idp[ms];
bool mark[ms];
bool imark[ms];
double sum[ms];
double sumK[ms];
 
double solve(int x) {
  if(mark[x]) return dp[x];
  mark[x] = 1;
  double &ans = dp[x] = 0;
  if(g[x].empty()) return ans;
  sum[x] = 0;
  sumK[x] = 0;
  for(auto e : g[x]) {
    sum[x] += (1 + solve(e.first))*e.second;
    sumK[x] += e.second;
  }
  return ans = sum[x] / sumK[x];
}
 
double isolve(int x) {
  if(imark[x]) return idp[x];
  if(!mark[x]) return 0;
  imark[x] = 1;
  double &ans = idp[x] = 0;
  if(x == 0) return ans = 1;
  for(auto e : ig[x]) {
    if(mark[e.first]) ans += isolve(e.first) * (e.second / sumK[e.first]);
  }
  return ans;
}
 
main() {
  cout << fixed << setprecision(9);
  int n, m;
  while(cin >> n >> m, n || m) {
    for(int i = 0; i < n; i++) {
      g[i].clear();
      ig[i].clear();
      mark[i] = 0;
      imark[i] = 0;
    }
    for(int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].emplace_back(v, w);
      ig[v].emplace_back(u, w);
    }
    double ans = solve(0);
    double best = 0;
    for(int i = 0; i < n; i++) {
      if(g[i].size() > 1 && mark[i]) {
        for(auto e : g[i]) {
          best = max(best, isolve(i) * ((sum[i] - (1 + solve(e.first)) * e.second) / (sumK[i] - e.second) - solve(i)));
        }
      }
    }
    cout << ans + best << '\n';
  }
}