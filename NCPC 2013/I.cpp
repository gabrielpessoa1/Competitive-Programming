#include <bits/stdc++.h>
using namespace std;

const int ms = 1e4+5;

int arr[ms];
int group[ms];
int sz[ms];
int ans[ms];
vector<int> szToGroups[ms];

void fail() {
  cout << "Impossible\n";
  exit(0);
}

void dfs(int u, int g) {
  if(group[u] && u != g) {
    fail();
  }
  if(group[u]) {
    return;
  }
  group[u] = g;
  sz[g]++;
  dfs(arr[u], g);
}

main() {
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for(int i = 1; i <= n; i++) {
    if(!group[i]) {
      dfs(i, i);
      szToGroups[sz[i]].push_back(i);
    }
  }
  for(int i = 1; i <= n; i++) {
    if(!szToGroups[i].empty()) {
      int x = i;
      while(x != i * __gcd(x, k)) {
        x = i * __gcd(x, k);
      }
      int cnt = x/i;
      if(szToGroups[i].size() % cnt != 0) {
        fail();
      }
      for(int w = 0; w < szToGroups[i].size() / cnt; w++) {
        vector<int> pos(x);
        for(int j = 0; j < cnt; j++) {
          int p = j;
          int cur = szToGroups[i][j + w * cnt];
          do {
            pos[p] = cur;
            cur = arr[cur];
            p = (p + k) % x;
          } while(p != j);
        }
        for(int i = 0; i < x; i++) {
          ans[pos[i]] = pos[(i+1)%x];
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    cout << ans[i];
    if(i != n) cout << ' ';
    else cout << '\n';
  }
}