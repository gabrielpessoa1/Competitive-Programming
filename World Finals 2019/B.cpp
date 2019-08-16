#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int ms = 1e4+5;
const int inf = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-7;

int n, h, a, b;
int x[ms], y[ms];
int dp[ms];

vii seg1;
vii seg2;
vii seg3;

void intersect() {
  seg2.clear();
  for(auto &s1 : seg1) {
    for(auto &s2 : seg3) {
      int lo = max(s1.first, s2.first);
      int hi = min(s1.second, s2.second);
      if(lo <= hi) seg2.push_back(ii(lo, hi));
    }
  }
  seg1.clear();
  if(!seg2.empty()) {
    sort(seg2.begin(), seg2.end());
    pair<int, int> cur = seg2[0];
    for(int i = 1; i < seg2.size(); i++) {
      if(cur.second >= seg2[i].first) {
        cur.second = seg2[i].second;
      } else {
        seg1.push_back(cur);
        cur = seg2[i];
      }
    }
    seg1.push_back(cur);
  }
  //cout << "SEGMENTOS: " << seg2.size() << endl;
}
int solveEquation(int l, int i) {
  int dx = x[i] - x[l];
  int dy = h - y[i];
  int delta = 2 * dx * dy;
  int lo = ceil(2 * (dx + dy - sqrt(delta)));
  int hi = floor(2 * (dx + dy + sqrt(delta)));
  seg3 = {ii(0, dy), ii(lo, hi)};
  return max(hi, dy);
}

main() {
  scanf("%d%d%d%d", &n, &h, &a, &b);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  dp[n-1] = a * (h-y[n-1]);
  for(int i = n-2; i > -1; i--) {
    dp[i] = inf;
    //seg1 = vii(1,ii(0, inf));
    int hi = solveEquation(i, i);
    for(int j = i + 1; j < n; j++) {
      //seg3 = {ii(x[j] - x[i], inf)};
      //intersect();
      hi = min(hi, solveEquation(i, j));
      int d = x[j] - x[i];
      if(d <= hi) {
        
          dp[i] = min(dp[i], dp[j] + a * (h - y[i]) + b * (d * d));
      }/*
      for(auto &s : seg1) {
        if(d >= s.first && d <= s.second) {
          dp[i] = min(dp[i], dp[j] + a * (h - y[i]) + b * (d * d));
        }
      }*/
    }
    //cout << "Ans no " << i << " = " << dp[i] << endl;
  }
  if(dp[0] == inf) {
    printf("impossible\n");
  } else {
    printf("%d\n", dp[0]);
  }
}