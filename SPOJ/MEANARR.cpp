// SPOJ
// MEANARR - Mean of array
// https://www.spoj.com/problems/MEANARR/

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef pair<long long, int> ii;

typedef tree<ii, null_type, less<ii>, rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

ordered_set os;

int main() {
  int n;
  long long k;
  cin >> n >> k;
  long long sum = 0;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    os.insert({sum, i});
    sum += x - k;
    ans += os.order_of_key({sum, i+1});
  }
  cout << ans << '\n';
}