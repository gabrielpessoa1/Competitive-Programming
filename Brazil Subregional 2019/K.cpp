#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;
const int m = 4;

struct Matrix {
  int mat[m][m];
  Matrix operator * (const Matrix &p) {
    Matrix ans;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < m; j++) {
        for(int k = ans.mat[i][j] = 0; k < m; k++) {
          ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * p.mat[k][j]) % mod;
        }
      }
    }
    return ans;
  }
};

Matrix fExp(Matrix a, int b) {
  Matrix ans;
  for(int i = 0; i < m; i++) for(int j = 0; j < m; j++)
    ans.mat[i][j] = i == j;
  while(b) {
    if(b & 1ll) ans = ans*a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

int intfexp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1ll) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

main() {
  Matrix base;
  base.mat[0][0] = 1;
  base.mat[0][1] = 1;
  base.mat[0][2] = 0;
  base.mat[0][3] = 1;
  base.mat[1][0] = 1;
  base.mat[1][1] = 0;
  base.mat[1][2] = 0;
  base.mat[1][3] = 0;
  base.mat[2][0] = 0;
  base.mat[2][1] = 1;
  base.mat[2][2] = 1;
  base.mat[2][3] = 0;
  base.mat[3][0] = 0;
  base.mat[3][1] = 0;
  base.mat[3][2] = 0;
  base.mat[3][3] = 1;
  Matrix mult;
  mult.mat[0][0] = 3;
  mult.mat[1][0] = 1;
  mult.mat[2][0] = 0;
  mult.mat[3][0] = 1;
  int n;
  cin >> n;
  if(n == 1) cout << 2 << endl;
  else {
    Matrix ans = fExp(base, n-2) * mult;
    cout << (ans.mat[0][0] + ans.mat[2][0]) % mod * intfexp(2, n+1) % mod << endl;
  }
}