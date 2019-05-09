// La Salle-Pui Ching Programming Challenge 培正喇沙編程挑戰賽 2018
// C - Consecutive Numbers
// https://codeforces.com/gym/101807/problem/C

#include <bits/stdc++.h>
using namespace std;

bool solve(int x) {
  for(int j = 0; j < 30; j++) {
    if(x == (1 << j)) return false;
  }
  return true;
}

int main() {
  int q;
  cin >> q;
  for(int i = 0; i< q; i++) {
    int x;
    cin >> x;
    if(solve(x)) {
     cout << "Yes\n";
    } else {
       cout << "No\n";   
    }
  }
}