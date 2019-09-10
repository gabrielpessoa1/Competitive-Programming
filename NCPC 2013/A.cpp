#include <bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int arr[ms];

main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr+n);
  reverse(arr, arr+n);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans = max(ans, i+2+arr[i]);
  }
  cout << ans << '\n';
}