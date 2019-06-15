// VTEX Code Cup 2019
// A - Automatic Light
// https://vtexcc19.kattis.com/problems/vtexcc19.automaticlight

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int ms = 1e5+5;

ii events[ms];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int ti, te;
    cin >> ti >> te;
    events[i] = {ti, 1};
    events[i+n] = {te, -1};
  }
  sort(events, events+n+n);
  int last = 0;
  int qnt = 0;
  int ans = 0;
  for(int i = 0; i < n + n; i++) {
    if(qnt) {
      ans = max(ans, events[i].first - last);
    }
    if(events[i].second == 1) last = events[i].first;
    qnt += events[i].second;
  }
  cout << ans << '\n';
}