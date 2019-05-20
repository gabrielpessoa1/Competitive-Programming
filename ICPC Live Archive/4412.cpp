// ICPC Live Archive
// 4412 - The Great Game
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2413

#include <bits/stdc++.h>
using namespace std;

const int ms = 1005;
const int inf = 0x3f3f3f3f;
const int m = 205;
const double eps = 1e-7;

int g, w, l;
double probs[ms][3];
pair<double, double> dp[ms][2*ms];
double k[ms];

double calc(double mi) {
  for(int i = 0; i <= 2*g; i++) {
    if(i == g) dp[g][i] = {0, 1};
    else if(i > g) dp[g][i] = {1, 0};
    else dp[g][i] = {0, 0};
  }
  for(int i = g-1; i >= 0; i--) {
    for(int j = g-i; j <= g+i; j++) {
      dp[i][j] = {0, 0};
      for(int k = 0; k < 3; k++) {
        pair<double, double> temp = {0, 0};
        for(int l = 0; l < 3; l++) {
          int idx = (k+l);
          if(idx >= 3) idx -= 3;
          int scoreChange = 0;
          if(l == 0) scoreChange = 1;
          else if(l == 2) scoreChange = -1;
          temp.first += dp[i+1][j+scoreChange].first * probs[i][idx];
          temp.second += dp[i+1][j+scoreChange].second * probs[i][idx];
        }
        if(temp.first + temp.second*mi > dp[i][j].first + dp[i][j].second*mi) dp[i][j] = temp;
      }
    }
  }
  return dp[0][g].first/(1-dp[0][g].second);
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cout << fixed << setprecision(3);
  while(cin >> g >> w >> l, g || w || l) {
    for(int i = 0; i < g; i++) {
      for(int j = 0; j < 3; j++) {
        cin >> probs[i][j];
        probs[i][j] /= 100;
      }
    }
    double lo = 0, hi = 1;
    for(int it = 0; it < 20; it++) {
      double m = (lo+hi)/2;
      if(calc(m) > m) lo = m;
      else hi = m;
    }
    double p = calc(lo);
    k[0] = 0;
    for(int i = 1; i < w+l; i++) {
      k[i] = (p/(1 - k[i-1]*(1-p)));
    }
    double ans = 1;
    for(int i = w+l-1; i >= l; i--) {
      ans *= k[i];
    }
    cout << ans*100 << "%\n";
  }
}