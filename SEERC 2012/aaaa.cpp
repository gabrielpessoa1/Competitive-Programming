#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
long long GCD(long long a, long long b) { 
  return (b == 0) ? a : GCD(b, a % b); 
}
inline long long get_LCM(long long a, long long b) { 
  return a / GCD(a, b) * b; 
}
inline long long normalize(long long x, long long mod) { 
  x %= mod; 
  if (x < 0) x += mod; 
  return x; 
}
 
 void Print(ll a) {
   cout << a << endl;
 }
struct GCD_type { 
  long long x, y, d; 
};
GCD_type ex_GCD(long long a, long long b){
  if (b == 0) return {1, 0, a};
  GCD_type pom = ex_GCD(b, a % b);
  cout << "ex_gcd " << endl;
  Print(pom.x);
  Print(pom.y);
  Print(pom.d);
  Print(a);
  Print(b);
  cout << "----" << endl;
  return {pom.y, pom.x - a / b * pom.y, pom.d};
}
 
ll magic(int n, vector<ll> a, vector<ll> b) {
  ll ans = b[0];
  ll lc = a[0];
  bool impossible = false;
  for (int i = 1; i < a.size(); i++) {
    Print(lc);
    Print(a[i]);
    cout << "---" << endl;
    auto p = ex_GCD(lc, a[i]);
    ll x1 = p.x;
    ll d = p.d;
    if ((b[i] - ans) % d != 0) {
      impossible = true;
    }
    assert(lc % d == 0);
    cout << ">>" << endl;
    Print(ans);
    Print(x1);
    Print(b[i]);
    Print(ans);
    Print(d);
    Print(a[i]);
    Print(lc);
    cout << " << - >>" << endl;
    Print(lc);
    Print(d);
    Print(a[i]);
    ans = normalize(ans + x1 * (b[i] - ans) / d % (a[i] / d) * lc, lc / d * a[i]);
    lc = get_LCM(lc, a[i]);
  }
  if (impossible) {
    return -1;
  }
  return normalize(ans, lc);
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef ONLINE_JUDGE
    freopen("h.in", "r", stdin);
  #endif
  int m;
  cin >> m;
  if (m == 0) {
    cout << 0 << endl;
    return 0;
  }
  vector<ll> d(m), val(m), rval(m);
  ll mx = 0, lc = 1;
  for (int i = 0; i < m; i++) {
    cin >> d[i];
    if (d[i] % 2 == 0) {
      val[i] = d[i] / 2 * (d[i] + 1);
    } else {
      val[i] = (d[i] + 1) / 2 * d[i];
    }
    mx = max(mx, val[i]);
    rval[i] = val[i] % d[i];
    lc = get_LCM(lc, d[i]);
    //cout << d[i] << ' ' << val[i] << ' ' << rval[i] << endl;
  }
  ll ans = magic(m, d, rval);
  //cout << "ans: " << ans << endl;
  if (ans == -1) {
    cout << 0 << endl;
  } else {
    ans += ((mx - ans) / lc) * lc;
    if (ans < mx) {
      ans += lc;
    }
    cout << ans << endl;
  }
  return 0;
}