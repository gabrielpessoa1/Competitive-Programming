#include <bits/stdc++.h>
using namespace std;
 
const int ms = 1e5+5;
 
struct state {
	int faces;
	int paints;
	int x, y;
	bool operator <(const state &p) const {
		if(faces != p.faces) return faces < p.faces;
		if(paints != p.paints) return paints < p.paints;
		if(x != p.x) return x < p.x;
		if(y != p.y) return y < p.y;		
		return false;
	}
};
 
typedef pair<int, state> dst;
 
int dist[1<<6][1<<6][20][20];
priority_queue<dst, vector<dst>, greater<dst>> pq;
string g[21];
int paint[21][21];
int go[4][6];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
 
main() {
	go[0][2] = 5;
	go[0][5] = 0;
	go[0][0] = 4;
	go[0][4] = 2;
	go[0][1] = 1;
	go[0][3] = 3;
	
	go[1][5] = 2;
	go[1][2] = 4;
	go[1][4] = 0;
	go[1][0] = 5;
	go[1][3] = 3;
	go[1][1] = 1;
	
	go[2][3] = 5;
	go[2][4] = 3;
	go[2][1] = 4;
	go[2][5] = 1;
	go[2][2] = 2;
	go[2][0] = 0;
	
	go[3][5] = 3;
	go[3][3] = 4;
	go[3][4] = 1;
	go[3][1] = 5;
	go[3][2] = 2;
	go[3][0] = 0;
	
	string s;
	while(getline(cin, s)) {
		g[0] = s;
		m = g[0].size();
		n = 1;
		while(getline(cin, s) && s != "") {
			g[n++] = s;
		}
		int paintsTillNow = 0;
		state inicio, fim;
		inicio.faces = 0;
		inicio.paints = (1 << 6) - 1;
		fim.faces = (1 << 6) - 1;
		fim.paints = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(g[i][j] == 'G') {
					fim.x = i; fim.y = j;
				}
				if(g[i][j] == 'C') {
					inicio.x = i; inicio.y = j;
				}
				if(g[i][j] == 'P') {
					paint[i][j] = paintsTillNow++;
				}
			}
		}
		memset(dist, 63, sizeof dist);
		pq.push({0, inicio});
		dist[inicio.faces][inicio.paints][inicio.x][inicio.y] = 0;
		while(!pq.empty()) {
			state cur = pq.top().second;
			int curD = pq.top().first;
			pq.pop();
			if(dist[cur.faces][cur.paints][cur.x][cur.y] != curD) continue;
			if(!(cur.faces & (1 << 5)) && g[cur.x][cur.y] == 'P' && cur.paints & (1 << paint[cur.x][cur.y])) {
				cur.faces |= (1 << 5);
				cur.paints ^= (1 << paint[cur.x][cur.y]);
				if(dist[cur.faces][cur.paints][cur.x][cur.y] > curD) {
					dist[cur.faces][cur.paints][cur.x][cur.y] = curD;
				} else {
					continue;
				}
			}
			for(int i = 0; i < 4; i++) {
				state going;
				going.faces = 0;
				for(int j = 0; j < 6; j++) {
					going.faces |= (((cur.faces & (1 << j)) >> j) << go[i][j]);
				}
				going.paints = cur.paints;
				going.x = cur.x + dx[i];
				going.y = cur.y + dy[i];
				if(going.x < 0 || going.x >= n || going.y < 0 || going.y >= m) continue;
				int cost = 1;
				if(cur.faces & (1 << 5)) cost = 3;
				if(g[cur.x][cur.y] == 'P' && cur.paints & (1 << paint[cur.x][cur.y])) {
					cost = 1;
				}
				int &gDist = dist[going.faces][going.paints][going.x][going.y];
				if(gDist > curD + cost) {
					gDist = curD + cost;
					pq.push({gDist, going});
				}
			}
		}
		cout << dist[fim.faces][fim.paints][fim.x][fim.y] << '\n';
	}
}