#include <bits/stdc++.h>
using namespace std;

int t1[15], t0[15];

main() {
  t1[1] = 1; t1[3] = 1; t1[5] = 1; t1[7] = 1; t1[8] = 1; t1[10] = 1; t1[12] = 1;
  t0[4] = 1; t0[6] = 1; t0[9] = 1; t0[11] = 1;
  int t;
  cin >> t;
  while(t--) {
    string a, b, c;
    cin >> a >> b >> c;
    string s = a+b+c;
    sort(s.begin(), s.end());
    string best = "999999999999999";
    int ans = 0;
    do {
      int year = stoi(s.substr(0, 4));
      int month = stoi(s.substr(4, 2));
      int day = stoi(s.substr(6, 2));
      if(year >= 2000 && day > 0 && day <= 31 && month <= 12 && month > 0) {
        bool bissext = year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
        if(t1[month] && day <= 31 || t0[month] && day <= 30 || day <= 28 && month == 2 || bissext && month == 2 && day <= 29) {
          ans++;
          best = min(best, s);
        }
      }
    } while(next_permutation(s.begin(), s.end()));
    printf("%d", ans);
    if(ans != 0) {
      int year = stoi(best.substr(0, 4));
      int month = stoi(best.substr(4, 2));
      int day = stoi(best.substr(6, 2));
      printf(" %02d %02d %04d", day, month, year);
    }
    printf("\n");
  }
  
}