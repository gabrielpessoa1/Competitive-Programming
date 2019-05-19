// Benelux Algorithm Programming Contest preliminaries 2018
// J - Jurassic Jigsaw
// https://open.kattis.com/problems/jurassicjigsaw

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int ms = 1005;
const int inf = 0x3f3f3f3f;

string s[ms];
vector<iii> edges;
vector<ii> mst;
int n;
int ds[ms];

int find(int u) {
  if(ds[u] != u) ds[u] = find(ds[u]);
  return ds[u];
}

bool dsUnion(int u, int v) {
  u = find(u); v = find(v);
  ds[u] = v;
  return u != v;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
  int m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) ds[i] = i;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    for(int j = 0; j < i; j++) {
      int unlike = 0;
      for(int k = 0; k < m; k++) {
        if(s[i][k] != s[j][k]) unlike++;
      }
      edges.push_back({unlike, {j, i}});
    }
  }
  int ans = 0;
  sort(edges.begin(), edges.end());
  for(auto e : edges) {
    if(dsUnion(e.second.first, e.second.second)) {
      mst.push_back({e.second.first, e.second.second});
      ans += e.first;
    }
  }
  cout << ans << '\n';
  for(auto p : mst) {
    cout << p.first << ' ' << p.second << endl;
  }
}
