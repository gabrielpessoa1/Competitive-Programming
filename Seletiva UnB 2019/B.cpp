// Seletiva UnB 2019
// B - Presente de Dia das Mães
// https://codeforces.com/group/btcK4I5D5f/contest/244688/problem/B

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e5+5;

int arr[ms];

main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int lo = 1, hi = 1e9+1;
  while(lo < hi) {
    int mi = (lo+hi)/2;
    int maes = 0;
    for(int i = 0; i < n; i++) {
      maes += arr[i]/mi;
    }
    if(maes >= m) lo = mi+1;
    else hi = mi;
  }
  cout << lo - 1 << endl;
}