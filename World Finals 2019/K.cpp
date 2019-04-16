// World Finals 2019
// K - Traffic Blights
// https://open.kattis.com/problems/trafficblights

#include <bits/stdc++.h>
using namespace std;

const int ms = 505;

int n;
int great[100];
int hit[100][100];
int x[ms];
int r[ms];
int g[ms];
int mod[ms];
double ans[ms];
double curAns[ms];
int qnt[ms];

int gcd(int a, int b) {
  while(b) a %= b, swap(a, b);
  return a;
}

main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d%d%d", &x[i], &r[i], &g[i]);
    mod[i] = r[i] + g[i];
  }
  int limit = 5*7*8*9;
  for(int i = 0; i <= n; i++) ans[i] = 0;
  for(int i = 0; i < limit; i++) {
    for(int a = 0; a <= n; a++) {
      curAns[a] = 1.0/limit;
    }
    for(int a = 1; a < 100; a++) {
      for(int b = 0; b < a; b++) {
        hit[a][b] = n;
      }
    }
    for(int a = n-1; a > -1; a--) {
      int gc = gcd(limit, mod[a]);
      int k = mod[a] / gc;
      int theMod = k;
      int divisao = 1;
      if(k == 5) {
        theMod *= 5;
        divisao = 5;
      } else if( k == 7) {
        theMod *= 7;
        divisao = 7;
      } else if(k == 3 || k == 9) {
        theMod *= 9;
        divisao = 9;
      } else if(k == 2 || k == 4 || k == 8) {
        theMod *= 8;
        divisao = 8;
      }
      //b % a == i, b % limit == x
      for(int b = 0; b < mod[a]; b++) {
        if(b % gc == i % gc) {
          int ac = (b % theMod) / divisao;
          if((b + x[a]) % mod[a] < r[a]) hit[k][ac] = a;
        }
      }
    }
    for(int a = 1; a < 100; a++) {
      if(a == 2 || a == 4 || a == 3) {
        int c = (a == 3) ? 9 : 8;
        for(int b = 0; b < c; b++) {
          hit[c][b] = min(hit[a][b%a], hit[c][b]);
        }
        continue;
      }
      for(int b = 0; b <= n+1; b++) {
        qnt[b] = 0;
      }
      for(int b = 0; b < a; b++) {
        qnt[hit[a][b]]++;
      }
      for(int b = n; b >= 0; b--) {
        qnt[b] += qnt[b+1];
        curAns[b] *= 1.0*qnt[b]/a;
      }
    }
    curAns[n+1] = 0;
    for(int a = 0; a <= n; a++) {
      ans[a] += curAns[a] - curAns[a+1];
    }
  }
  for(int i = 0; i <= n; i++) {
    printf("%.12f\n", ans[i]);
  }
}
