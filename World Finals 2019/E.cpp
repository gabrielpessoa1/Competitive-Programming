// World Finals 2019
// E - Dead-End Detector
// https://open.kattis.com/problems/deadend

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int ms = 5e5+5;
const int me = 5e5+5;

vector<int> g[ms];
int comp[ms], compSz = 0;
ii ans[ms];
int ansSz = 0;

int in[ms], vis[ms], t = 0;

int cycle[ms];
ii bridges[ms];
int bridSz;

void dfsComp(int u, int c, int p) {
	if(comp[u] == c) {
		cycle[c] = u;
		return;
	}	
	comp[u] = c;
	for(auto v : g[u]) {
		if(v != p) {
			dfsComp(v, c, u);
		}
	}
}

bool dfsBrid(int u, int p) {
	if(vis[u]) return false;
	in[u] = ++t;
	vis[u] = 1;
	bool valid = true;
	for(auto v : g[u]) {
		if(v != p) {
			if(dfsBrid(v, u)) {
				while(bridSz && in[bridges[bridSz-1].second] > in[v]) bridSz--;
				bridges[bridSz++] = ii(u, v);
			} else {
				valid = false;
			}
		}
	}
	return valid;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		if(!comp[i]) {
			dfsComp(i, ++compSz, -1);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!cycle[comp[i]] && g[i].size() == 1) {
			ans[ansSz++] = ii(i, g[i][0]);
		}
	}
	for(int i = 1; i <= compSz; i++) {
		if(cycle[i]) {
			dfsBrid(cycle[i], -1);
		}
	}
	for(int i = 0; i < bridSz; i++) {
		ans[ansSz++] = bridges[i];
	}
	sort(ans, ans+ansSz);
	printf("%d\n", ansSz);
	for(int i = 0; i < ansSz; i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}