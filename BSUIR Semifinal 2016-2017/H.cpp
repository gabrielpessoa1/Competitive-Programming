#include <bits/stdc++.h>
using namespace std;

const int ms = 1e4+5;

int arr[ms];
long long qntFirst[32];
long long qnt[32];

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 20; j++) {
      qntFirst[j] += (arr[i] & (1 << j)) != 0;
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 20; j++) {
      long long myCount = 0;
      if(arr[i] & (1 << j)) {
        myCount = n - qntFirst[j];
      } else {
        myCount = qntFirst[j];
      }
      qnt[j] += myCount;
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 20; j++) {
      long long myCount = 0;
      if(arr[i] & (1 << j)) {
        myCount = n*n - qnt[j];
      } else {
        myCount = qnt[j];
      }
      ans += myCount * (1 << j);
    }
  }
  cout << ans << endl;
}