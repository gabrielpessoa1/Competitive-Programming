#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e5+7;
const int mod = 1e9+7;

int n, m;
int a[2][ms];
int f[ms][7];

const int hi = 7; // size of matrix

struct Matrix { 
  int mat[hi][hi];
  int k;
  Matrix(int sz, int uni = 0) {
    k = sz;
    if(!uni) {
      for(int i = 0; i < k; i++) mat[0][i] = 1;
      for(int i = 1; i < k; i++) for(int j = 0; j < k; j++) 
        mat[i][j] = (i-1) == j;
    } else {
      for(int i = 0; i < k; i++) for(int j = 0; j < k; j++)
        mat[i][j] = i == j;
    }
  }
  Matrix operator * (const Matrix &p) {
    Matrix ans(k);
    for(int i = 0; i < k; i++)
      for(int j = 0; j < k; j++)
        for(int l = ans.mat[i][j] = 0; l < k; l++)
          ans.mat[i][j] = (ans.mat[i][j] + mat[i][l] * p.mat[l][j]) % ms;
    return ans;
  }
};

void printe(Matrix a) {
  cout << "-----------" << endl;
  for(int i = 0; i < a.k; i++) {
    for(int j = 0; j < a.k; j++) 
      cout << a.mat[i][j] << ' ';
    cout << endl;
  }
  cout << "-----------" << endl;
}

int fexp(int sz, int b) {
  //cout << sz << ' ' << b << endl;
  if(b <= 0 || sz == 1) return 1;
  if(sz == 0) return 0;
  b--;
  Matrix a(sz);
  Matrix ans(sz, 1);
  //printe(a);
  //printe(ans);
  while(b) {
    if(b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  //printe(ans);
  int trueAns = 0;
  for(int i = 0; i < sz; i++) trueAns += ans.mat[sz-1][i];
  return trueAns % ms;
}

main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  a[0][0] = 1;
  a[1][0] = 1;
  int c, j, k;
  string s;
  while(m-- && cin >> s >> j >> k >> c) {
    int idx = s[0] - 'a';
    a[idx][j] += c;
    a[idx][k+1] -= c;
    if(k < j) {
      a[idx][0] += c;
      a[idx][n+1] -= c;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 2; j++) a[j][i] += a[j][i-1];
    ans += fexp(a[1][i] % 7, a[0][i]);
  }
  cout << ans << '\n';
}