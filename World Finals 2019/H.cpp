// World Finals 2019
// H - Hobson's Trains
// https://open.kattis.com/problems/hobsonstrains

#include <bits/stdc++.h>
using namespace std;

const int ms = 5e5+5;
const int inf = 0x3f3f3f3f;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;


int nxt[25][ms];
int extra[25][ms];
int root[ms];
int go[ms];
int visited[ms], visiting[ms];
int ans[ms];
int topo[ms], tsz;
int nxtAns[ms], extraAns[ms];
int cycleSz[ms];
int cycleStart[ms];
int cyclePos[ms];
vector<int> cycleV[ms];

int add(int v, int sz) {
	int c = cycleStart[v];
	if(sz >= cycleSz[c]) {
		ans[c]++;
	} else {
		int resto = cycleSz[c] - cyclePos[v];
		if(resto < sz) {
			add(v, resto);
			add(c, sz - resto);
		} else {
			ans[v]++;
			int k = cyclePos[v] + sz;
			if(k != cycleSz[c]) {
				ans[cycleV[c][k]]--;
			}
		}
	}
}

void defineSz(int u, int v, int p) {
	if(u != v) {
		cycleSz[u] = cycleSz[v];
		cycleStart[u] = v;
		cyclePos[u] = p;
		cycleV[cycleStart[u]].push_back(u);
		defineSz(nxt[0][u], v, p + 1);
	}
}

int dfs(int v) {
	if(visited[v]) return root[v];
	if(visiting[v]) {
		root[v] = -1;
		cycleSz[v] = 1;
		cycleStart[v] = v;
		cyclePos[v] = 0;
		cycleV[v].push_back(v);
		return -1;
	}
	visiting[v] = 1;
	int ans;
	int k = dfs(nxt[0][v]);
	if(~k) ans = root[v] = k;
	else {
		if(root[v] == -1) {
			ans = root[v] = v;
			cycleSz[v] = cycleSz[nxt[0][v]];
			defineSz(nxt[0][v], v, 1);
		} else {
			root[v] = v;
			cycleSz[v] = cycleSz[nxt[0][v]] + 1;
			ans = -1;
		}
	}
	visited[v] = 1;
	topo[tsz++] = v;
	return ans;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		nxt[0][i] = x-1;
		go[i] = x-1;
	}
	for(int i = 0; i < n; i++) {
		dfs(i);
	}
	reverse(topo, topo+n);
	for(int i = 0; i < n; i++) {
		if(root[i] == i) {
			nxt[0][i] = i;
			extra[0][i] = 1;
		}
	}
	for(int k = 1; k < 20; k++) {
		for(int i = 0; i < n ; i++) {
			if(!extra[k-1][i]) {
				nxt[k][i] = nxt[k-1][nxt[k-1][i]];
			} else {
				nxt[k][i] = nxt[k-1][i];
			}
			extra[k][i] = extra[k-1][i] + extra[k-1][nxt[k-1][i]];
		}
	}
	for(int i = 0; i < n; i++) {
		nxtAns[i] = i;
		extraAns[i] = 0;
		for(int j = 19; j > -1; j--) {
			if((1 << j) & k) {
				int agora = nxtAns[i];
				if(!extraAns[i]) {
					agora = nxt[j][nxtAns[i]];
				}
				extraAns[i] += extra[j][nxtAns[i]];
				nxtAns[i] = agora;
			}
		}
		ans[i]++;
		ans[nxt[0][nxtAns[i]]]--;
	}
	for(int i = 0; i < n; i++) {
		int v = topo[i];
		if(v != root[v]) {
			ans[nxt[0][v]] += ans[v];
		}
	}
	for(int i = 0; i < n; i++) {
		if(root[i] == nxtAns[i]) {
			add(root[i], extraAns[i] + 1);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < cycleV[i].size(); j++) {
			ans[cycleV[i][j]] += ans[cycleV[i][j-1]];
		}
	}
	for(int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}
}