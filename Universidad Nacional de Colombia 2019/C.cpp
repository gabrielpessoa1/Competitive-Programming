#include <bits/stdc++.h>
using namespace std;

const int ms = 2003;
const int shift = 1001;

int dp[ms], dp2[ms];
int main() {
  string a, b;
  cin >> a >> b;
  int n = a.size();
  for(int i = 0; i < n; i++) {
    for(int j = max(-1000, -i); j <= min(1000, n-i-1); j++) {
      if(a[i] == b[i+j]) dp[j+shift] = dp[j+shift]+1;
      else dp[j+shift] = max(dp[j+shift-1], dp[j+shift+1]);
    }
  }
  if(dp[shift] * 100 >= 99 * n) {
    cout << "Long lost brothers D:\n";
  } else {
    cout << "Not brothers :(\n";
  }
}