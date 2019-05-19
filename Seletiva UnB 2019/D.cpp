// Seletiva UnB 2019
// D - Lista de Exercícios
// https://codeforces.com/group/btcK4I5D5f/contest/244688/problem/D

#include <bits/stdc++.h>
using namespace std;

main() {
  int d;
  cin >> d;
  if(d == 1) cout << 3 << ' ' << 4 << endl << 5 << ' ' << 7 << endl;
  else if (d == -1) cout << -3 << ' ' << -4 << endl << 5 << ' ' << 7 << endl;
  else if(d == 2) cout << 3 << ' ' << -4 << endl << -1 << ' ' << 2 << endl;
  else if(d == -2) cout << -3 << ' ' << 4 << endl << -1 << ' ' << 2 << endl;
  else if(d == 0) cout << 1 << ' ' << -2 << endl << -1 << ' ' << 2 << endl;
  else cout << 2 << ' ' << -1 << endl << -d << ' ' << d << endl;
}