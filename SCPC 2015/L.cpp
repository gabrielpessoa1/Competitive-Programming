#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int isPrime[30];
int qnt[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  for(int i = 2; i < 30; i++) {
    isPrime[i] = 1;
    for(int j = 2; j < i; j++) {
      if(i % j == 0) isPrime[i] = 0;
    }
  }
  for(int i = 0; i < ms-1; i++) {
    int cnt = 0;
    for(int j = 0; j < 20; j++) {
      if(i & (1 << j)) cnt++;
    }
    qnt[i+1] = qnt[i];
    if(isPrime[cnt]) qnt[i+1]++;
  }

  int t;
  cin >> t;
  while(t--) {
    int l, r;
    cin >> l >> r;
    cout << qnt[r+1] - qnt[l] << '\n';
  }
}