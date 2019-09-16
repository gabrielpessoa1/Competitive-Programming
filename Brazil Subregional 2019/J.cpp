#include <bits/stdc++.h>
using namespace std;

const int ms = 15;

vector<int> c[ms];

int count(int id, int j) {
  int ans = 0;
  for(int x : c[id]) if(x == j) ans++;
  return ans;
}

int rmv(int k, int id) {
  int idx = -1;
  for(int i = 0; i < c[k].size(); i++) {
    if(c[k][i] == id) idx = i;
  }
  c[k].erase(c[k].begin() + idx);
}

main() {
  int n, k;
  cin >> n >> k;
  k--;
  int joker = 1;
  c[k].push_back(-1);
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < 4; j++) {
      if(s[j] == 'A') c[i].push_back(1);
      else if(s[j] == 'D') c[i].push_back(10);
      else if(s[j] == 'Q') c[i].push_back(11);
      else if(s[j] == 'J') c[i].push_back(12);
      else if(s[j] == 'K') c[i].push_back(13);
      else c[i].push_back(s[j] - '0');
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 1; j <= 13; j++) {
      if(c[i].size() == 4 && count(i, j) == 4) {
        cout << i + 1 << endl;
        return 0;
      }
    }
  }
  while(true) {
    if(count(k, -1) > 0) {
      joker = !joker;
    }
    int card = -2;
    if(joker && count(k, -1) > 0) {
      card = -1;
    }
    for(int i = 1; i <= 4 && card == -2; i++) {
      for(int j = 1; j <= 13 && card == -2; j++) {
        if(count(k, j) == i) {
          card = j;
        }
      }
    }
    rmv(k, card);
    for(int i = 1; i <= 13; i++) {
      if(count(k, i) == 4) {
        cout << k + 1 << endl;
        return 0;
      }
    }
    k = (k+1) % n;
    c[k].push_back(card);
  }
}