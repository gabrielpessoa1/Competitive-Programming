// Seletiva UnB 2019
// K - Máquina de Refrigerante
// https://codeforces.com/group/btcK4I5D5f/contest/244688/problem/K

#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;
const int m = 101;

int n;

struct Matrix { 
  double mat[m][m];
  Matrix operator * (const Matrix &p) {
    Matrix ans;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        for(int k = ans.mat[i][j] = 0; k < n; k++)
          ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * p.mat[k][j]);
    return ans;
  }
};

Matrix fExp(Matrix a, int b) {
  Matrix ans;	
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
    ans.mat[i][j] = i == j;
  while(b) {
    if(b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}

Matrix base;

main() {
  int u, f, m;
  cin >> n >> u >> f >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> base.mat[i][j];
      if(j == f) base.mat[i][j] = 0;
    }
  }
  Matrix matAns = fExp(base, m);
  double ans = 0;
  for(int i = 0; i < n; i++) {
    ans += matAns.mat[u][i];
  }
  cout << fixed << setprecision(7) << ans << endl;
}