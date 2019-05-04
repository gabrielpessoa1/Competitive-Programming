// North America Qualifier 2018
// B - Bingo Ties
// https://open.kattis.com/problems/bingoties

#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, q;
  cin >> p >> q;
  int s;
  cin >> s;
  int x = p*q/__gcd(p, q);
  if(x <= s) {
    cout << "yes\n";
  } else {
    cout << "no\n";
  }
}