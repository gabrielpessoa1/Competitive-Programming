// North America Qualifier 2018
// A - Bingo Ties
// https://open.kattis.com/problems/bingoties

#include <bits/stdc++.h>
using namespace std;

const int ms = 1e4+5;

int n;
int cards[105][5][5];
int number[3005];

int solve() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 5; j++) {
      bool achou = true;
      for(int k = 0; k < 5; k++) {
        if(!number[cards[i][j][k]]) achou = false;
      }
      if(achou) return false;
    }
  }
  return true;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 5; j++) {
      for(int k = 0; k < 5; k++) {
        cin >> cards[i][j][k];
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      for(int p1 = 0; p1 < 5; p1++) {
        for(int p2 = 0; p2 < 5; p2++) {
          vector<int> v;
          for(int k = 0; k < 5; k++) {
            v.emplace_back(cards[i][p1][k]);
            v.emplace_back(cards[j][p2][k]);
          }
          sort(v.begin(), v.end());
          auto last = std::unique(v.begin(), v.end());
          v.erase(last, v.end()); 
          if(v.size() != 10) {
            for(int k : v) {
              number[k] = 1;
            }
            for(int k : v) {
              number[k] = 0;
              if(solve()) {
                cout << i+1 << ' ' << j+1 << '\n';
                return 0;
              }
              number[k] = 1;
            }
            for(int k : v) {
              number[k] = 0;
            }
          }
        }
      }
    }
  }
  cout << "no ties\n";
}