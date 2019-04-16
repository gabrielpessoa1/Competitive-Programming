// World Finals 2019
// D - Circular DNA
// https://open.kattis.com/problems/circular

#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> ii;

const int ms = 1e6+5;
const int inf = 0x3f3f3f3f;

vector<ii> g[ms];
int a[ms];
int st[ms];
int invalid[ms];
int sum[ms];

void add(int i, int j) {
	if(i <= j) {
		sum[i]++;
		sum[j+1]--;
	} else {
		sum[i]++;
		sum[1]++;
		sum[j+1]--;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int k = 1e6;
	for(int i = 1; i <= n; i++) {
		int x;
		char c;
		scanf(" %c%d", &c, &x);
		int t = (c == 's') ? 1 : -1;
		g[x].push_back({t, i});
		invalid[x] += t;
	}
	for(int i = 1; i <= k; i++) {
		if(invalid[i] || g[i].size() == 0) continue;
		st[i] = g[i].size() - 1;
		int qnt = g[i][st[i]].first;
		while(qnt < 0) {
			qnt += g[i][--st[i]].first;
		}
		for(int j = 0; j < st[i]; j++) {
			qnt += g[i][j].first;
			while(qnt < 0) {
				qnt += g[i][--st[i]].first;
			}
		}
		qnt = g[i][st[i]].first;
		int ultimoFim = -1;
		for(int j = (st[i]+1)%g[i].size(); j != st[i]; j++) {
			if(!qnt) {
				add(ultimoFim, g[i][j].second);
			}
			qnt += g[i][j].first;
			if(!qnt) {
				ultimoFim = g[i][j].second+1;
			}
			if(j == g[i].size() - 1) j = -1;
		}
		add(ultimoFim, g[i][st[i]].second);
	}
	int cur = 0;
	int ans = 0;
	int pos = 1;
	for(int i = 0; i <= n; i++) {
		cur += sum[i];
		if(cur > ans) {
			ans = cur;
			pos = i;
		}
	}
	printf("%d %d\n", pos, ans);
}