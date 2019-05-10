// BSUIR Semifinal 2016-2017
// B - Traveling Salesman Problem
// https://codeforces.com/gym/102134/problem/B

#include <bits/stdc++.h>
using namespace std;

string s;

void solve(long long a, long long b) {
  if(a == 1) {
    for(int i = 0; i < b; i++) {
      s.push_back('0');
    }
  } else {
    for(int i = 2; i <= b; i++) {
      if(a < (1ll << i)) {
        solve((1ll << i) - a, i);
        s.push_back('1');
        for(int j = i; j < b; j++) {
          s.push_back('0');
        }
        return;
      }
    }
  }
}

int main() {
  long long a, b;
  cin >> a >> b;
  solve(a, b);
  cout << s << '\n';
}