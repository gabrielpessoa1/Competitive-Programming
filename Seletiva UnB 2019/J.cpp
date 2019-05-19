// Seletiva UnB 2019
// J - Fabricação de Caixas
// https://codeforces.com/group/btcK4I5D5f/contest/244688/problem/J

#include <bits/stdc++.h>
using namespace std;

#define int long long

main() {
  int v, a;
  cin >> v >> a;
  for(int b = 1; true; b++) {
    int b2 = b*b;
    int areaRight = a - 2*b*b;
    if(v % b2 == 0 && areaRight > 0 && areaRight % (4*b) == 0 && v / b2 == areaRight / (4*b)) {
      cout << b << ' ' << v / b2 << endl;
      return 0;
    }
  }
}