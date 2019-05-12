// SPOJ
// GIVEAWAY - Give Away
// https://www.spoj.com/problems/GIVEAWAY/

#include <bits/stdc++.h>
using namespace std;

const int gsz = 3000, ms = 5e5+5;

int arr[ms];
vector<int> blocks[ms];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    blocks[i/gsz].emplace_back(arr[i]);
  }
  int lastGroup = (n-1)/gsz;
  for(int i = 0; i <= lastGroup; i++) {
    sort(blocks[i].begin(), blocks[i].end());
  }
  int q;
  scanf("%d", &q);
  for(int i = 0; i < q; i++) {
    int type;
    scanf("%d", &type);
    if(type == 0) {
      int a, b, c, ans = 0;
      scanf("%d %d %d", &a, &b, &c);
      a--; b--;
      for(int j = a; j <= b; ) {
        if(j % gsz == 0 && j + gsz - 1 <= b) {
          int gIdx = j/gsz;
          ans += gsz - (lower_bound(blocks[gIdx].begin(), blocks[gIdx].end(), c) - blocks[gIdx].begin());
          j += gsz;
        } else {
          ans += arr[j] >= c;
          j++;
        }
      }
      printf("%d\n", ans);
    } else {
      int a, b;
      scanf("%d%d", &a, &b);
      a--;
      int gIdx = a/gsz;
      for(int j = 0; j < blocks[gIdx].size(); j++) {
        if(blocks[gIdx][j] == arr[a]) {
          blocks[gIdx][j] = b;
          int idx = j;
          while(idx > 0 && blocks[gIdx][idx] < blocks[gIdx][idx-1]) {
            swap(blocks[gIdx][idx], blocks[gIdx][idx-1]);
            idx--;
          }
          while(idx < blocks[gIdx].size() - 1 && blocks[gIdx][idx] > blocks[gIdx][idx+1]) {
            swap(blocks[gIdx][idx], blocks[gIdx][idx+1]);
            idx++;
          }
          break;
        }
      }
      arr[a] = b;
    }
  }
}