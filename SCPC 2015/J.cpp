#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

map<string, int> dic;
string iDic[ms];
int z;
int vis[ms];
vector<int> g[ms];
vector<int> ans;

int get(string &s) {
  if(!dic.count(s)) {
    dic[s] = z;
    iDic[z++] = s;
  }
  return dic[s];
}

int dfs(int u) {
  if(vis[u]) return 0;
  vis[u] = 1;
  for(int v : g[u]) dfs(v);
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    for(int i = 0; i < z; i++) {
      g[i].clear();
      vis[i] = 0;
    }
    z = 0;
    dic.clear();
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
      string s;
      int m;
      cin >> s >> m;
      int u = get(s);
      for(int j = 0; j < m; j++) {
        cin >> s;
        g[u].push_back(dic[s]);
      }
    }
    for(int i = 0; i < k; i++) {
      string s;
      cin >> s;
      dfs(dic[s]);
    }
    for(int i = 0; i < z; i++) {
      if(vis[i]) cout << iDic[i] << '\n';
    }
  }
}