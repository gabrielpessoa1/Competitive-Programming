// North America Qualifier 2018
// D - Froggie
// https://open.kattis.com/problems/froggie

#include <bits/stdc++.h>
using namespace std;

const int ms = 20;

int l, w;
int offset[ms], interval[ms], speed[ms];

int squish(int x, int y, int t) {
  if(x < 1 || x > l || y < 1 || y > w) {
    return 0;
  }
  x = l - x + 1;
  if(x % 2 == 0) {
    y = w - y - 1;
  }
  int carP = (offset[x] + speed[x] * (t)); 
  if(speed[x] == 0 && abs(y - carP) % (interval[x]) == 0) {
    return 1;
  }
  for(int k = 1; k <= speed[x]; k++) {
    int novoCarP = (carP + k);
    if(abs(y - novoCarP) % (interval[x]) == 0) {
      return 1;
    }
  }
  return 0;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> l >> w;
  for(int i = 1; i <= l; i++) {
    cin >> offset[i] >> interval[i] >> speed[i];
  }
  int x = 0;
  int y;
  cin >> y;
  string s;
  cin >> s;
  int t = 0;
  for(char c : s) {
    if(c == 'U') {
      x++;
    } else if(c == 'D') {
      x--;
    } else if(c == 'L') {
      y--;
    } else if(c == 'R') {
      y++;
    }
    if(squish(x, y, t)) {
      cout << "squish\n";
      return 0;
    }
    t++;
  }
  if(x > l) {
    cout << "safe\n";
  } else {
    cout << "squish\n";
  }
}