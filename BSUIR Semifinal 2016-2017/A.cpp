// BSUIR Semifinal 2016-2017
// A - Tennis
// https://codeforces.com/gym/102134/problem/A

#include <bits/stdc++.h>
using namespace std;

const int lim = 20;

long double p[2];

long double dp[4][4][10][10][2];
bool vis[4][4][10][10][2];
long double dpGame[lim][lim][2];
bool visGame[lim][lim][2];
long double dpTiebreaker[lim][lim][2];
bool visTiebreaker[lim][lim][2];


long double playGame(int pt1, int pt2, int server) {
  if(pt1 == lim) return 1;
  if(pt2 == lim) return 0;
  if(pt1 == lim - 1 && pt2 == lim - 1) {
    if((1 - p[server]*(1 - p[server]) - p[server]*(1 - p[server])) < 1e-10) return 0;
    if(p[server]*p[server] + 1e-10 > (1 - p[server]*(1 - p[server]) - p[server]*(1 - p[server]))) return 1;
    return p[server]*p[server] / (1 - p[server]*(1 - p[server]) - p[server]*(1 - p[server]));
  }
  long double &ans = dpGame[pt1][pt2][server];
  if(visGame[pt1][pt2][server]) return ans;
  visGame[pt1][pt2][server] = 1;
  ans = 0;
  if(pt1 >= 4 && pt1 - pt2 >= 2) {
    ans = 1;
  } else if(pt2 >= 4 && pt2 - pt1 >= 2) {
    ans = 0;
  } else {
    ans = p[server] * playGame(pt1 + 1, pt2, server) + (1 - p[server]) * playGame(pt1, pt2 + 1, server);
  }
  return ans;
}

long double playTiebreaker(int pt1, int pt2, int server) {
  if(pt1 == lim) return 1;
  if(pt2 == lim) return 0;
  if(pt1 == lim - 1 && pt2 == lim - 1) {
    if((1 - p[server]*(1 - p[!server]) - p[!server]*(1 - p[server])) < 1e-10) return 0;
    if(p[server]*p[!server] + 1e-10 > (1 - p[server]*(1 - p[!server]) - p[!server]*(1 - p[server]))) return 1;
    return p[server]*p[!server] / (1 - p[server]*(1 - p[!server]) - p[!server]*(1 - p[server]));
  }
  long double &ans = dpTiebreaker[pt1][pt2][server];
  if(visTiebreaker[pt1][pt2][server]) return ans;
  visTiebreaker[pt1][pt2][server] = 1;
  ans = 0;
  if(pt1 >= 7 && pt1 - pt2 >= 2) {
    ans = 1;
  } else if(pt2 >= 7 && pt2 - pt1 >= 2) {
    ans = 0;
  } else {
    int nserver = server;
    if((pt1 + pt2) % 2 == 0) nserver = !nserver;
    ans = p[server] * playTiebreaker(pt1 + 1, pt2, nserver) + (1 - p[server]) * playTiebreaker(pt1, pt2 + 1, nserver);
  }
  return ans;
}


long double playMatch(int set1, int set2, int game1, int game2, int server) {
  long double &ans = dp[set1][set2][game1][game2][server];
  if(vis[set1][set2][game1][game2][server]) return ans;
  vis[set1][set2][game1][game2][server] = 1;
  ans = 0;
  if(set1 == 3) ans = 1;
  else if (set2 == 3) ans = 0;
  else if(game1 == 6 && game2 == 6) {
    long double p = playTiebreaker(0, 0, server);
    ans = p * playMatch(set1+1, set2, 0, 0, !server) + (1-p) * playMatch(set1, set2+1, 0, 0, !server);
  } else if(game1 == 7 && game2 == 5 || game1 == 6 && game2 < 5) {
    ans = playMatch(set1 + 1, set2, 0, 0, server);
  } else if(game2 == 7 && game1 == 5 || game2 == 6 && game1 < 5) {
    ans = playMatch(set1, set2 + 1, 0, 0, server);
  } else {
    long double p = playGame(0, 0, server);
    ans = p * playMatch(set1, set2, game1 + 1, game2, !server) + (1 - p) * playMatch(set1, set2, game1, game2 + 1, !server);
  }
  return ans;
}

int main() {
  cout << fixed << setprecision(12);
  cin >> p[0] >> p[1];
  cout << playMatch(0, 0, 0, 0, 0) << '\n';
}