#include <bits/stdc++.h>
using namespace std;

vector<int> g[5];
int deg[5];

main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for(int i = 0; i < 5; i++) {
    string s;
    cin >> s;
    if(s[1] == '<') swap(s[0], s[2]);
    deg[s[0] - 'A']++;
    g[s[2]-'A'].push_back(s[0]-'A');
  }
  queue<int> q;
  vector<int> ans;
  for(int i = 0; i < 5; i++) if(deg[i] == 0) q.push(i);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    ans.push_back(u);
    for(int v : g[u]) if(--deg[v] == 0) q.push(v);
  }
  if(ans.size() < 5) cout << "impossible\n";
  else {
    for(int i : ans) {
      cout << (char) ('A' + i);
    }
    cout << '\n';
  }
}