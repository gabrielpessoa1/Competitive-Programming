// Benelux Algorithm Programming Contest preliminaries 2018
// A - Appalling Architecture
// https://open.kattis.com/problems/appallingarchitecture

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int ms = 105;

string s[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int h, w;
  cin >> h >> w;
  string s;
  int left = 200, right = -1;
  int sum = 0, qnt = 0;
  for(int i = 0; i < h; i++) {
    cin >> s;
    for(int j = 0; j < w; j++) {
      if(s[j] != '.') {
        if(i == h - 1) {
          left = min(left, j);
          right = max(right, j);
        }
        qnt++;
        sum += j;
      }
    }
  }
  if(2*sum < 2*left*qnt - qnt) {
    cout << "left\n";
  } else if(2*sum> 2*right*qnt + qnt) {
    cout << "right\n";
  } else {
    cout << "balanced\n";
  }
}