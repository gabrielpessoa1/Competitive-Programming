#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 1<<18;
const int inf = 0x3f3f3f3f;
 
vector<vector<int>> triangles = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11}, {12, 13, 14}, {15, 16, 17}, {2, 4, 6}, {5, 10, 12}, {8, 13, 15}};
 
int ans[ms];
 
main() {
  ans[ms-1] = 0;
  for(int i = ms-2; i >= 0; i--) {
    ans[i] = -inf;
    for(int j = 0; j < 18; j++) {
      if(!(i & (1 << j))) {
        int t = 0;
        for(auto &k : triangles) {
          int contemJ = 0, existe = 0;
          for(auto l : k) {
            if(l == j) contemJ = 1;
            else if(i & (1 << l)) existe++;
          }
          if(existe == 2 && contemJ) t++;
        }
        if(t) ans[i] = max(ans[i], ans[i | (1 << j)]+t);
        else ans[i] = max(ans[i], -ans[i | (1 << j)]);
      }
    }
  }
  int n;
  while(cin >> n, n) {
    int k = 0;
    while(n--) {
      int x;
      cin >> x;
      k |= (1 << (x-1)); 
    }
    if(ans[k] > 0) cout << "Andy wins\n";
    else if(ans[k] < 0) cout << "Ralph wins\n";
    else cout << "Draw\n";
  }
}