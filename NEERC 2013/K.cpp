#include <bits/stdc++.h>
using namespace std;
 
const int ms = 1e6+5;
 
int arr[ms];
int qnt[ms];
int bu[ms];
vector<int> ans;
 
void printe() {
  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if(i != ans.size() - 1) cout << ' ';
  }
  cout << '\n';
  exit(0);
}
 
main() {
  cin.tie(0); ios::sync_with_stdio(0);
  #ifdef ONLINE_JUDGE
  freopen("kabaleo.in", "r", stdin);
  freopen("kabaleo.out", "w", stdout);
  #endif
  int n, p, c, h;
  cin >> n >> p >> c >> h;
  int last;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    qnt[arr[i]]++;
  }
  for(int i = 0; i < p; i++) {
    cin >> last;
    bu[last]++;
  }
  int vc = min(n, max(0, qnt[h] - (p-1-bu[h])));
  if(vc == 0 && last == h) vc = 1;
  if(vc == n && last != h) vc = n - 1;
  int needNerf = -1;
  for(int i = 1; i <= c; i++) {
    if(i == h) continue;
    int x = max(0, min(n, qnt[i] + bu[i]));
    if(last != i && x == n) x = n - 1;
    int xNerf = max(0, min(n, qnt[i] - 1 + bu[i]));
    if(last != i && xNerf == n) xNerf = n - 1;
    if(last == i && xNerf == 0) xNerf = 1;
    //cout << x << ' ' << xNerf << ' ' << vcBuffing << endl;
    if(xNerf >= vc) printe();
    else if(x >= vc && needNerf == -1) needNerf = i;
    else if(x >= vc) printe();
  }
  if(needNerf == -1) {
    for(int i = 1; i <= n; i++) {
      if(arr[i] != h) ans.push_back(i);
    }
  } else {
    for(int i = 1; i <= n; i++) {
      if(arr[i] == needNerf) ans.push_back(i);
    }
  }
  int perdeNerfandoVc = 0;
  vc = min(n, max(0, qnt[h] - (p-bu[h])));
  if(vc == 0 && last == h) vc = 1;
  if(vc == n && last != h) vc = n - 1;
  for(int i = 1; i <= c; i++) {
    if(i == h) continue;
    int x = max(0, min(n, qnt[i] + bu[i]));
    if(last != i && x == n) x = n - 1;
    if(x >= vc) perdeNerfandoVc = 1;
  }
  if(!perdeNerfandoVc) {
    for(int i = 1; i <= n; i++) {
      if(arr[i] == h) ans.push_back(i);
    }
  }
  printe();
}
