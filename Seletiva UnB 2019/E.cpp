// Seletiva UnB 2019
// E - Construindo Estradas
// https://codeforces.com/group/btcK4I5D5f/contest/244688/problem/E

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f3f3f3f3fll;
const int ms = 1e5+5;

typedef pair<int, int> ii;

vector<ii> a, b;
int totalValue = 0;

vector<ii> getFourMaximum(vector<ii> &a) {
  vector<ii> ans;
  for(int i = 0; i < 4; i++) {
    ans.emplace_back(0, -1);
  }
  for(int i = 0; i < a.size(); i++) {
    ii myPair = {a[i].first, i};
    for(int j = 0; j < 4; j++) {
      if(myPair > ans[j]) {
        for(int k = 3; k > j; k--) {
          ans[k] = ans[k-1];
        }
        ans[j] = myPair;
        break;
      }
    }
  }
  return ans;
}

vector<ii> getFourMid(vector<ii> &a) {
  vector<ii> ans;
  for(int i = 0; i < 4; i++) {
    ans.emplace_back(inf, -1);
  }
  for(int i = 0; i < a.size(); i++) {
    ii myPair = {a[i].second - a[i].first, i};
    for(int j = 0; j < 4; j++) {
      if(myPair < ans[j]) {
        for(int k = 3; k > j; k--) {
          ans[k] = ans[k-1];
        }
        ans[j] = myPair;
        break;
      }
    }
  }
  return ans;
}

int twoHalfs() {
  vector<ii> mA = getFourMaximum(a);
  vector<ii> mB = getFourMaximum(b);
  vector<ii> midA = getFourMid(a);
  vector<ii> midB = getFourMid(b);
  if(a.size() == 1 && b.size() == 1) {
    return min(a[0].first + b[0].second, a[0].second + b[0].first);
  }
  if(b.size() == 1) {
    a.swap(b);
  }
  if(a.size() == 1) {
    int ans = inf;
    for(int i = 0; i < 2; i++) {
      ans = min(ans, totalValue - a[0].first + a[0].second - a[0].first - mB[i].first);
      for(int j = 0; j < 2; j++) {
        if(mB[i].second != midB[j].second) {
          ans = min(ans, totalValue - a[0].first + midB[j].first - mB[i].first);
        }
      }
    }
    return ans;
  }
  int ans = inf;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        if(mA[i].second != midA[k].second) {
          ans = min(ans, totalValue - mA[i].first - mB[j].first + midA[k].first);
        }
        if(mB[j].second != midB[k].second) {
          ans = min(ans, totalValue - mA[i].first - mB[j].first + midB[k].first);
        }
      }
    }
  }
  return ans;
}

int inTheMiddle() {
  vector<ii> mA = getFourMaximum(a);
  vector<ii> mB = getFourMaximum(b);
  vector<ii> midA = getFourMid(a);
  vector<ii> midB = getFourMid(b);
  if(b.size() == 2) {
    if(a.size() == 1) {
      return min(a[0].first + b[0].second, a[0].second + b[0].first) + min(a[0].first + b[1].second, a[0].second + b[1].first);
    } else {
      int ans = inf;
      for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
          if(midA[i].second != midA[j].second) {
            ans = min(ans, totalValue - b[0].first - b[1].first + midA[i].first + midA[j].first);
          }
          if(midB[i].second != midB[j].second) {
            ans = min(ans, totalValue - b[0].first - b[1].first + midB[i].first + midB[j].first);
          }
          ans = min(ans, totalValue - b[0].first - b[1].first + midA[i].first + midB[j].first);
        }
      }
      return ans;
    }
  }
  int ans = inf;
  for(int firstB = 0; firstB < 4; firstB++) {
    for(int secondB = firstB+1; secondB < 4; secondB++) {
      for(int firstMid = 0; firstMid < 4; firstMid++) {
        for(int secondMid = 0; secondMid < 4; secondMid++) {
          if(firstMid != secondMid) {
            ans = min(ans, totalValue - mB[firstB].first - mB[secondB].first + midA[firstMid].first + midA[secondMid].first);
          }
          if(firstMid != secondMid && midB[secondMid].second != mB[firstB].second && midB[secondMid].second != mB[secondB].second) {
            ans = min(ans, totalValue - mB[firstB].first - mB[secondB].first + midB[firstMid].first + midB[secondMid].first);
          }
          ans = min(ans, totalValue - mB[firstB].first - mB[secondB].first + midA[firstMid].first + midB[secondMid].first);
        }
      }
    }
  }
  return ans;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if(x < y) a.emplace_back(x, y);
    else b.emplace_back(y, x);
    totalValue += min(x, y) * 2;
  }
  if(b.size() == 0) {
    a.swap(b);
  }
  if(a.size() == 0) {
    int big = 0, big2 = 0;
    for(int i = 0; i < b.size(); i++) {
      if(b[i].first > big) {
        big2 = big;
        big = b[i].first;
      } else {
        big2 = max(b[i].first, big2);
      }
    }
    cout << totalValue - big - big2 << endl;
    return 0;
  }
  int ans = twoHalfs();
  if(b.size() > 1) {
    ans = min(ans, inTheMiddle());
  }
  if(a.size() > 1) {
    a.swap(b);
    ans = min(ans, inTheMiddle());
  }
  cout << ans << endl;
}