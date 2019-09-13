#include<bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 2e5+5, sigma = 26;

int len[ms*2], link[ms*2], nxt[ms*2][sigma];
int sz, last;

void build(string &s) {
  len[0] = 0; link[0] = -1;
  sz = 1; last = 0;
  memset(nxt[0], -1, sizeof nxt[0]);
  for(char ch : s) {
    int c = ch-'a', cur = sz++;
    len[cur] = len[last]+1;
    memset(nxt[cur], -1, sizeof nxt[cur]);
    int p = last;
    while(p != -1 && nxt[p][c] == -1) {
      nxt[p][c] = cur; p = link[p];
    }
    if(p == -1) {
      link[cur] = 0;
    } else {
      int q = nxt[p][c];
      if(len[p] + 1 == len[q]) {
        link[cur] = q;
      } else {
        len[sz] = len[p]+1; link[sz] = link[q];
        memcpy(nxt[sz], nxt[q], sizeof nxt[q]);
        while (p != -1 && nxt[p][c] == q) {
          nxt[p][c] = sz; p = link[p];
        }
        link[q] = link[cur] = sz++;
      }
    }
    last = cur;
  }
}

int dp[2*ms];

int solve(int p) {
  if(~dp[p]) return dp[p];
  dp[p] = 1;
  for(int i = 0; i < 26; i++) {
    if(~nxt[p][i]) dp[p] += solve(nxt[p][i]);
  }
  return dp[p];
}

void get(int p, int k) {
  if(k == 0) return;
  for(int i = 0; i < 26; i++) {
    if(dp[nxt[p][i]] >= k) {
      cout << (char) (i + 'a');
      get(nxt[p][i], k-1);
      return;
    } else {
      k -= dp[nxt[p][i]];
    }
  }
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  string s;
  cin >> s;
  build(s);
  memset(dp, -1, sizeof dp);
  solve(0);
  int q;
  cin >> q;
  while(q--) {
    int k;
    cin >> k;
    get(0, k);
    cout << '\n';
  }
}