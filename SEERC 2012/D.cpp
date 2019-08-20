#include <bits/stdc++.h>
using namespace std;
 
const int ms = 1e7+5;
const int inf = 0x3f3f3f3f;
 
int trie[ms][2], terminal[ms], z;
 
void init() {
  memset(trie[0], -1, sizeof trie[0]);
  terminal[0] = -1;
  z = 1;
}
 
void insert(long long p, int k, int idx) {
  int cur = 0;
  for(int i = 0; i < k; i++) {
    int id = (bool) (p & (1 << (31 - i)));
    if(trie[cur][id] == -1) {
      memset(trie[z], -1, sizeof trie[z]);
      terminal[z] = -1;
      trie[cur][id] = z++;
    }
    cur = trie[cur][id];
  }
  terminal[cur] = idx;
}
 
int query(unsigned int p) {
  int cur = 0;
  int ans = terminal[0];
  for(int i = 0; i < 32; i++) {
    int id = (bool) (p & (1 << (31 - i)));
    if(trie[cur][id] == -1) return ans;
    cur = trie[cur][id];
    if(~terminal[cur]) ans = terminal[cur];
  }
  return ans;
}
 
main() {
  #ifdef ONLINE_JUDGE
  freopen("d.in", "r", stdin);
  #endif
  cin.tie(0); ios::sync_with_stdio(0);
  init();
  int x, y;
  cin >> x >> y;
  for(int i = 0; i < x; i++) {
    string s; int k;
    cin >> s >> k;
    insert(stoll(s, nullptr, 16), k, i);
  }
  for(int i = 0; i < y; i++) {
    string s;
    cin >> s;
    cout << query(stoll(s, nullptr, 16)) << '\n';
  }
}