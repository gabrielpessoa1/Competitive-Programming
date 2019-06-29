#include <bits/stdc++.h>
using namespace std;
 
int k, w, h, n, W, H;
string s[20][20];
int bu[20], bl[20], br[20], bd[20];
int bp[20][20];
char rb[150][150];
vector<int> vl, vr, vu, vd, vm;
 
void checkBoard() {
  memset(rb, '.', sizeof rb);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int a = 0; a < 3*h-2; a++) {
        for(int b = 0; b < 3*w-2; b++) {
          int p = bp[i][j];
          if(s[p][a][b] != '.') {
            int na = h*i - (h-1) + a;
            int nb = w*j - (w-1) + b;
            if(rb[na][nb] != '.') return;
            rb[na][nb] = s[p][a][b];
          }
        }
      }
    }
  }
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cout << rb[i][j];
    }
    cout << '\n';
  }
  exit(0);
}
 
main() {
  cin.tie(0); ios::sync_with_stdio(0);
  #ifdef ONLINE_JUDGE
  freopen("ascii.in", "r", stdin);
  freopen("ascii.out", "w", stdout);
  #endif
  cin >> k >> w >> h;
  n = 1;
  if(k == 4) n = 2;
  if(k == 9) n = 3;
  if(k == 16) n = 4;
  W = n*w; H = n*h;
  cout << W << ' ' << H << '\n';
  if(n == 1) {
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        cout << 'A';
      }
      cout << '\n';
    }
    return 0;
  }
  for(int p = 0; p < k; p++) {
    for(int i = 0; i < 3*h-2; i++) {
      cin >> s[p][i];
    }
    bu[p] = 1; bl[p] = 1; br[p] = 1; bd[p] = 1;
    for(int i = 0; i < 3*w-2; i++) {
      if(s[p][h-2][i] != '.') bu[p] = 0;
      if(s[p][h+h-1][i] != '.') bd[p] = 0;
      if(i >= w-1 && i <= w+w-2) {
        if(s[p][h-1][i] == '.') bu[p] = 0;
        if(s[p][h+h-2][i] == '.') bd[p] = 0;
      } else {
        if(s[p][h-1][i] != '.') bu[p] = 0;
        if(s[p][h+h-2][i] != '.') bd[p] = 0;
      }
    }
    for(int i = 0; i < 3*h-2; i++) {
      if(s[p][i][w-2] != '.') bl[p] = 0;
      if(s[p][i][w+w-1] != '.') br[p] = 0;
      if(i >= h-1 && i <= h+h-2) {
        if(s[p][i][w-1] == '.') bl[p] = 0;
        if(s[p][i][w+w-2] == '.') br[p] = 0;
      } else {
        if(s[p][i][w-1] != '.') bl[p] = 0;
        if(s[p][i][w+w-2] != '.') br[p] = 0;
      }
    }
  }
  if(n == 2) {
    for(int i = 0; i < 4; i++) {
      if(bu[i] && bl[i]) bp[0][0] = i;
      else if(bu[i] && br[i]) bp[0][1] = i;
      else if(bd[i] && bl[i]) bp[1][0] = i;
      else if(bd[i] && br[i]) bp[1][1] = i;
    }
    checkBoard();
  }
  if(n == 3) {
    for(int i = 0; i < 9; i++) {
      if(bu[i] && bl[i]) bp[0][0] = i;
      else if(bu[i] && br[i]) bp[0][2] = i;
      else if(bu[i]) bp[0][1] = i;
      else if(bd[i] && bl[i]) bp[2][0] = i;
      else if(bd[i] && br[i]) bp[2][2] = i;
      else if(bd[i]) bp[2][1] = i;
      else if(bl[i]) bp[1][0] = i;
      else if(br[i]) bp[1][2] = i;
      else bp[1][1] = i;
    }
    checkBoard();
  }
  if(n == 4) {
    for(int i = 0; i < 16; i++) {
      if(bu[i] && bl[i]) bp[0][0] = i;
      else if(bu[i] && br[i]) bp[0][3] = i;
      else if(bd[i] && bl[i]) bp[3][0] = i;
      else if(bd[i] && br[i]) bp[3][3] = i;
      else if(bu[i]) vu.push_back(i);
      else if(bd[i]) vd.push_back(i);
      else if(bl[i]) vl.push_back(i);
      else if(br[i]) vr.push_back(i);
      else vm.push_back(i);
    }
    do {
      bp[1][1] = vm[0];
      bp[1][2] = vm[1];
      bp[2][1] = vm[2];
      bp[2][2] = vm[3];
      for(int iu = 0; iu < 2; iu++) {
       bp[0][1] = vu[iu];
       bp[0][2] = vu[!iu];
       for(int il = 0; il < 2; il++) {
        bp[1][0] = vl[il];
        bp[2][0] = vl[!il];
        for(int ir = 0; ir < 2; ir++) {
          bp[1][3] = vr[ir];
          bp[2][3] = vr[!ir];
          for(int id = 0; id < 2; id++) {
            bp[3][1] = vd[id];
            bp[3][2] = vd[!id];
            checkBoard();
          }
        }
       }
      }
    } while(next_permutation(vm.begin(), vm.end()));
    assert(0);
  }
}