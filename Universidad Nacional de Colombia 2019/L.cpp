#include <bits/stdc++.h>
using namespace std;

const int ms = 1e6+5;
const int HI = 1e6;

int n;
int drop[ms];
int dp[ms];
vector<int> pos;

int query(int x) {
  vector<int> qry(n);
  for(int i = n-1; i >= 0; i--) {
    while(x - drop[i] >= 0 && dp[x-drop[i]]) {
      qry[i]++;
      x -= drop[i];
    }
  }
  cout << 1 << endl;
  for(int i = 0; i < n; i++) {
    cout << qry[i];
    if(i != n - 1) cout << ' ';
    else cout << endl;
  }
  string s;
  cin >> s;
  if(s[0] == 'r') return 1;
  else if(s[0] == 'y') return 0;
  else return -1;
}

void gg(int x) {
  cout << 2 << endl << x << endl;
  exit(0);
}

main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> drop[i];
  dp[0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = drop[i]; j <= HI; j++) {
      dp[j] |= dp[j-drop[i]];
    }
  }
  for(int i = 1; i <= HI; i++) {
    if(dp[i]) pos.push_back(i);
  }
  int lo = 0, hi = ((int) pos.size()) -1;
  while(lo + 1 < hi) {
    int mi = (lo+hi)/2;
    int cmp = query(pos[mi]);
    if(cmp == 0) {
      gg(pos[mi]);
    } else if(cmp == 1) {
      hi = mi;
    } else {
      lo = mi;
    }
  }
  int cmpLo = query(pos[lo]);
  int cmpHi = query(pos[hi]);
  if(cmpLo == 0) gg(pos[lo]);
  else if(cmpHi == 0) gg(pos[hi]);
  else if(cmpLo == 1) {
    if(pos[lo] == 2) gg(1);
    else gg(-1);
  } else if(cmpHi == -1) {
    if(pos[hi] == HI - 1) gg(HI);
    else gg(-1);
  } else {
    if(pos[hi] - 1 == pos[lo] + 1) gg(pos[lo] + 1);
    else gg(-1);
  }
}