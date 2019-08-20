#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 75;

int fib[ms];
int dp[ms];
int total[ms];

int solve(int cnt) {
  if(cnt == 0) return 0;
  for(int j = 1; j < 75; j++) {
    if(fib[j] > cnt) {
      int ans =  dp[j-1] + (cnt - fib[j-1]+1) + solve(cnt - fib[j-1]);
      return ans;
    }
  }
}

int miss(int n, int k, int lft) {
  if(lft == 0) return 0;
  return n/fib[k] + miss(n%fib[k], k-1, lft-1);
}

main() {
  #ifdef ONLINE_JUDGE
  freopen("fibonacci.in", "r", stdin);
  freopen("fibonacci.out", "w", stdout);
  #endif  
  fib[1] = 1;
  fib[2] = 2;
  dp[1] = 0;
  dp[2] = 1;
  total[1] = 0;
  total[2] = 1;
  for(int i = 3; i < 75; i++) {
    fib[i] = fib[i-1] + fib[i-2];
    dp[i] = dp[i-1] + dp[i-2] + fib[i-2];
    total[i] = total[i-1] + fib[i-2]*(i-1);
  }
  int n;
  cin >> n;
  if(n == 0) {
    cout << 0 << endl;
    return 0;
  }
  for(int i = 1; i < 75; i++) {
    if(total[i] >= n) {
      int qnt = fib[i-1] - 1 + (n - total[i-1])/(i-1);
      int left = (n - total[i-1])%(i-1);
      cout << solve(qnt) + miss(qnt+1, i-1, left) << '\n';
      return 0;
    }
  }
}