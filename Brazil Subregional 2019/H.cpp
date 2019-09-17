#include <bits/stdc++.h>
using namespace std;

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  for(int i = 1; i < 10; i++) {
    cout << (a*b*i+9)/10 << " \n"[i == 9];
  }
}