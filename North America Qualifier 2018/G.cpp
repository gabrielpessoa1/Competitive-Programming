// North America Qualifier 2018
// G - Left and Right
// https://open.kattis.com/problems/leftandright

#include <bits/stdc++.h>
using namespace std;

const int ms = 2e5+2;

typedef pair<char, int> ii;


int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  string s;
  cin >> n >> s;
  char cur = '1';
  int qnt = 0;
  vector<ii> v;
  for(char c : s) {
    if(c == cur) qnt++;
    else {
      if(cur != '1') {
        v.push_back({cur, qnt});
      }
      qnt = 1;
      cur = c;
    }
  }
  v.push_back({cur, qnt});
  int pos = 1;
  for(int i = 0; i < v.size(); i++) {
    char c = v[i].first;
    int q = v[i].second;
    if(c == 'R') {
      for(int j = 0; j < q; j++) {
        cout << pos+j << '\n';
      }
      if(i == v.size() - 1) {
        cout << pos + q << '\n';
      }

      pos += q;
    } else {
      for(int j = 0; j < q; j++) {
        cout << pos + q - j << '\n';
      }
      cout << pos << '\n';
      pos += q+1;
      if(i != v.size() - 1) {
        v[i+1].second--;
      }
    }
  }
}