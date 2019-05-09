// La Salle-Pui Ching Programming Challenge 培正喇沙編程挑戰賽 2018
// I - Infection
// https://codeforces.com/gym/101807/problem/I

#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

set<int> s;
vector<int> g[ms];
int order[ms];
int vis[ms];
bool possible[ms];
int n, m;

void solve(int idx) {
  for(int i = 0; i < idx; i++) {
    cout << order[i] << ' ';
    vis[order[i]] = 1;
    if(i) s.erase(order[i]);
    for(int k : g[order[i]]) {
      if(!vis[k]) s.insert(k);
    }
  }
  int toRemove;
  if(idx) {
    toRemove = *s.upper_bound(order[idx]);
    s.erase(toRemove);
  } else {
    toRemove = order[0] + 1;
  }
  cout << toRemove << ' ';
  vis[toRemove] = 1;
  for(int k : g[toRemove]) {
    if(!vis[k]) s.insert(k);
  }
  for(int i = idx+1; i < n; i++) {
    int x = *s.begin();
    s.erase(x);
    vis[x] = 1;
    for(int k : g[x]) {
      if(!vis[k]) s.insert(k);
    }
    cout << x << ' ';
  }
  cout << '\n';
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
   int u, v;
   cin >> u >> v;
   g[u].push_back(v);
   g[v].push_back(u);
  }
  for(int i = 0; i < n; i++) {
    cin >> order[i];
    if(!i) possible[0] = order[0] != n;
    if(s.upper_bound(order[i]) != s.end()) {
      possible[i] = 1;
    }
    if(i) s.erase(order[i]);
    vis[order[i]] = 1;
    for(int k : g[order[i]]) {
      if(!vis[k]) s.insert(k);
    }
  }
  memset(vis, 0, sizeof vis);
  for(int i = n - 1; i >= 0; i--) {
    if(possible[i]) {
      solve(i);
      return 0;
    }
  }
  cout << -1 << '\n';
}