#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;
const int ms = 1e6+5;

int marked[ms][2];
int fat[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int qnt[2] = {0, 0};
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if(marked[a][0]++) {
      cout << 0 << endl;
      return 0;
    } else if(marked[b][1]++) {
      cout << 0 << endl;
      return 0;
    }
    if(a % 2 != b % 2) {
      cout << 0 << endl;
      return 0;
    } else {
      qnt[a%2]++;
    }
  }
  fat[0] = 1;
  for(int i = 1; i < ms; i++) {
    fat[i] = (fat[i-1] * i) % mod;
  }
  cout << fat[(n/2)-qnt[0]] * fat[((n-1)/2)+1-qnt[1]] % mod << endl;
}