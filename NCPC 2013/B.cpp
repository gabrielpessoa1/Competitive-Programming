#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair<double, int> pdi;
typedef pair<pdi, int> pdii;

const int N = 1010;
const int K = 3;
const ld inf = 1e12;

int main () {
  double num;
  int n;
  scanf("%lf %d", &num, &n);
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  set<pdii> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    s.insert({{w[i], 1}, i});
  }
  while(1) {
    ld hi = s.rbegin()->first.first;
    ld lo = s.begin()->first.first;
    if(lo/hi > num) break;
    int q = s.rbegin()->first.second;
    int id = s.rbegin()->second;
    s.erase(*s.rbegin());
    ans++;
    s.insert({{hi*q/(q+1), q+1}, id});
  }
  cout << ans << endl;
}