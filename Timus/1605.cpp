// Timus Online Judge
// 1605 - Devil's Sequence
// http://acm.timus.ru/problem.aspx?space=1&num=1605

#include <bits/stdc++.h>
using namespace std;

main() {
  int n;
  cin >> n;
  double ans = log10(2)*(n-1);
  if(n % 2 == 0) {
    ans += log10(2);
  }
  cout << floor(ans) << endl;
}