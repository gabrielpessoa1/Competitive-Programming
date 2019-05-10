// BSUIR Semifinal 2016-2017
// D - Viktoria and resentments
// https://codeforces.com/gym/102134/problem/D

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef pair<int, int> ii;

typedef tree<ii, null_type, less<ii>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

ordered_set os;

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int p, q;
  cin >> p >> q;
  string s;
  cin >> s;
  int sum = 0;
  long long ans = 0;
  for(int i = 0; i < s.size(); i++) {
    os.insert({sum, i});
    sum += (s[i] - '0') * q - p;
    ans += os.order_of_key({sum-1, i});
  }
  cout << ans << '\n';
}