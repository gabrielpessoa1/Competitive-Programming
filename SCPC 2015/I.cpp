#include <bits/stdc++.h>
using namespace std;

#define int long long

int l, r, T;
int dp[40][40][3][3][3][3];
int vis[40][40][3][3][3][3];
int da[2][2] = {{0, 1}, {0, 1}};
int db[2][2] = {{0, 1}, {1, 0}};

// 0 = no constraint, 1 = light constraint, 2 = heavy constraint
int getLo(int i, int j, int lo, int lb, int rb, int lim) {
  int ans;
  if(lo == 0) ans = 0;
  else if(lb == (bool) (lim & (1ll << i))) {
    if(rb == -1 || rb == (bool) (lim & (1ll << j))) {
      ans = lo;
    } else if(rb == 0) {
      ans = 2;
    } else {
      ans = 1;
    }
  } else if(lb == 0) {
    ans = 3;
  } else {
    ans = 0;
  }
  return ans;
}

int solve(int i, int j, int aLo, int aHi, int bLo, int bHi) {
  if(aLo > 2 || aHi > 2 || bLo > 2 || bHi > 2) return 0;
  if(i < j) return aLo < 2 && aHi < 2 && bLo < 2 && bHi < 2;
  int &visP = vis[i][j][aLo][aHi][bLo][bHi];
  int &ans = dp[i][j][aLo][aHi][bLo][bHi];
  if(visP == T) return ans;
  visP = T;
  ans = 0;
  if(i == j) {
    for(int al = 0; al < 2; al++) {
      for(int bl = 0; bl < 2; bl++) {
        int curAlo = getLo(i, j, aLo, al, -1, l);
        int curAhi = getLo(i, j, aHi, !al, -1, r);
        int curBlo = getLo(i, j, bLo, bl, -1, l);
        int curBhi = getLo(i, j, bHi, !bl, -1, r);
        ans += solve(i-1, j, curAlo, curAhi, curBlo, curBhi);
      }
    }
  } else {
    for(int x = 0; x < 2; x++) {
      for(int al = 0; al < 2; al++) {
        if(j || x) {
          for(int ar = 0; ar < 2; ar++) {
            int bl = x ? !al : al, br = x ? !ar : ar;
            int curAlo = getLo(i, j, aLo, al, ar, l);
            int curAhi = getLo(i, j, aHi, !al, !ar, r);
            int curBlo = getLo(i, j, bLo, bl, br, l);
            int curBhi = getLo(i, j, bHi, !bl, !br, r);
            ans += solve(i-1, j+1, curAlo, curAhi, curBlo, curBhi);
          }
        } else {
          int bl = al;
          int curAlo = getLo(i, j, aLo, al, -1, l);
          int curAhi = getLo(i, j, aHi, !al, -1, r);
          int curBlo = getLo(i, j, bLo, bl, -1, l);
          int curBhi = getLo(i, j, bHi, !bl, -1, r);
          ans += solve(i-1, j, curAlo, curAhi, curBlo, curBhi);
        }
      }
    }
  }
  return ans;
}

main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  for(T = 1; T <= t; T++) {
    cin >> l >> r;
    r = ~r;
    cout << solve(39, 0, 1, 1, 1, 1) << '\n';
  }
}