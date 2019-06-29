#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 2005;
const int me = 1e5+5;
 
int adj[ms], to[me], ant[me], wt[me], z;
int copy_adj[ms], fila[ms], level[ms];
 
void clear() {
	memset(adj, -1, sizeof adj);
	z = 0;
}
 
void add(int u, int v, int k = 1) {
	to[z] = v;
	ant[z] = adj[u];
	wt[z] = k;
	adj[u] = z++;
	swap(u, v);
	to[z] = v;
	ant[z] = adj[u];
	wt[z] = 0;
	adj[u] = z++;
}
 
int bfs(int source, int sink) {
	memset(level, -1, sizeof level);
	level[source] = 0;
	int front = 0, size = 0, v;
	fila[size++] = source;
	while(front < size) {
		v = fila[front++];
		for(int i = adj[v]; i != -1; i = ant[i]) {
			if(wt[i] && level[to[i]] == -1) {
				level[to[i]] = level[v] + 1;
				fila[size++] = to[i];
			}
		}
	}
	return level[sink] != -1;
}
 
int dfs(int v, int sink, int flow) {
	if(v == sink) return flow;
	int f;
	for(int &i = copy_adj[v]; i != -1; i = ant[i]) {
		if(wt[i] && level[to[i]] == level[v] + 1 && (f = dfs(to[i], sink, min(flow, wt[i])))) {
			wt[i] -= f;
			wt[i ^ 1] += f;
			return f;
		}
	}
	return 0;
}
 
int maxflow(int source, int sink) {
	int ret = 0, flow;
	while(bfs(source, sink)) {
		memcpy(copy_adj, adj, sizeof adj);
		while((flow = dfs(source, sink, 1 << 30))) {
			ret += flow;
		}
	}
	return ret;
}
 
int n, m;
string g[ms];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
 
int getid(int i, int j) {
	return i*m + j;
}
 
main() {
	cin.tie(0); ios::sync_with_stdio(0);
	string s;
	while(getline(cin, s)) {
		clear();
		g[0] = s;
		m = g[0].size();
		n = 1;
		while(getline(cin, s) && s != "") {
			g[n++] = s;
		}
		int src = 998, snk = 999;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(g[i][j] == 'W') add(src, getid(i, j));
				if(g[i][j] == 'N') add(getid(i, j)+1000, snk);
				add(getid(i, j), getid(i, j) + 1000);
				for(int k = 0; k < 4; k++) {
					int a = i + dx[k], b = j + dy[k];
					if(a > -1 && b > -1 && a < n && b < m) {
						if((g[i][j] == 'W' && g[a][b] == 'I') || (g[i][j] == 'I' && g[a][b] == 'N')) {
							add(getid(i, j)+1000, getid(a, b));
						}
					}
				}
			}
		}
		cout << maxflow(src, snk) << '\n';
	}
}