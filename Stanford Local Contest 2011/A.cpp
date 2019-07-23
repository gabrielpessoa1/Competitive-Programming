#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
char win[300];
 
 
char solve(int v) {
  if(v == 0) return 'R';
  if(v == 1) return 'P';
  if(v == 2) return 'S';
  else {
    int k = 3;
    while(k*3 <= v) {
      k *= 3;
    }
    return win[solve(v-k)];
  }
}
 
main() {
  int n;
  win['P'] = 'S';
  win['S'] = 'R';
  win['R'] = 'P';
  while(cin >> n, n) {
    cout << win[solve(n-1)] << '\n';
  }
}