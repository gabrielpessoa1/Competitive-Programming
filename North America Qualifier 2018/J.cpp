// North America Qualifier 2018
// J - Peg Game for Two
// https://open.kattis.com/problems/peggamefortwo

#include <bits/stdc++.h>
using namespace std;

const int ms = 105;

int peb[5][5];
int movesX[6] = {0, 0, 1, 1, -1, -1};
int movesY[6] = {1, -1, 0, 1, -1, 0};

bool valid(int i, int j) {
  return (i > -1 && i < 5 && j > -1 && j <= i);
}

int solve() {
  int ans = -0x3f3f3f3f;
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j <= i; j++) {
      for(int mov = 0; mov < 6; mov++) {
        int i2 = i + movesX[mov];
        int j2 = j + movesY[mov];
        int i3 = i2 + movesX[mov];
        int j3 = j2 + movesY[mov];
        if(valid(i2, j2) && valid(i3, j3) && peb[i][j] && peb[i2][j2] && !peb[i3][j3]) {
          int hold = peb[i2][j2];
          peb[i2][j2] = 0;
          peb[i3][j3] = peb[i][j];
          peb[i][j] = 0;
          ans = max(ans, hold * peb[i3][j3] - solve());
          peb[i2][j2] = hold;
          peb[i][j] = peb[i3][j3];
          peb[i3][j3] = 0;
        }
      }
    }
  }
  if(ans == -0x3f3f3f3f) return 0;
  return ans;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j <= i; j++) {
      cin >> peb[i][j];
    }
  }
  cout << solve() << '\n';
}