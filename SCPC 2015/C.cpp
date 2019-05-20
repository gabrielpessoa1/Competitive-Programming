#include <bits/stdc++.h>
using namespace std;

const int ms = 5e5+5;
const int inf = 0x3f3f3f3f;

int trie[ms][30];
int lo[ms], hi[ms];
int mark[ms];
int pos[ms];
string word[ms];
int z;
int ti;

void insert(string &s, int i) {
  int cur = 0;
  for(char c : s) {
    if(trie[cur][c-'a'] == -1) {
      memset(trie[z], -1, sizeof trie[z]);
      mark[z] = 0;
      trie[cur][c-'a'] = z++;
    }
    cur = trie[cur][c-'a'];
  }
  mark[cur] = i;
}

void dfs(int i) {
  lo[i] = ti;
  if(mark[i]) {
    pos[mark[i]] = ti++;
  }
  for(int j = 0; j < 26; j++) {
    if(~trie[i][j]) dfs(trie[i][j]);
  }
  hi[i] = ti;
}

int solve(int i) {
  int cur = 0;
  int ans = inf;
  for(int j = 0; j <= word[i].size(); j++) {
    if(j > 0) cur = trie[cur][word[i][j-1] - 'a'];
    ans = min(ans, j + 1 + (pos[i] - lo[cur]));
    ans = min(ans, j + 1 + (hi[cur] - pos[i]));
  }
  return ans;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) {
    z = 1;
    ti = 0;
    memset(trie[0], -1, sizeof trie[0]);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> word[i];
      insert(word[i], i);
    }
    dfs(0);
    for(int i = 1; i <= n; i++) {
      cout << solve(i);
      if(i != n) cout << ' ';
    }
    cout << '\n';
  }
}