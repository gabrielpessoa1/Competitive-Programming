#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
 
map<int, int> dist;
int dir[4] = {1, 8, 3, 6};
int cost[4];
 
int vectorToInt(vector<int> &v) {
	int ans = 0;
	for(int i = 0; i < 9; i++) {
		ans = ans * 10 + v[i];
	}
	return ans;
}
 
vector<int> intToVector(int x) {
	vector<int> v(9);
	for(int i = 8; i >= 0; i--) {
		v[i] = x % 10;
		x /= 10;
	}
	return v;
}
 
main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int h, v;
	while(cin >> h >> v, h || v) {
		cost[0] = cost[1] = h;
		cost[2] = cost[3] = v;
		vector<int> s(9), e(9);
		for(int i = 0; i < 9; i++) {
			cin >> s[i];
		}
		for(int i = 0; i < 9; i++) {
			cin >> e[i];
		}
		dist.clear();
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.emplace(0, vectorToInt(s));
		dist[vectorToInt(s)] = 0;
		while(!pq.empty()) {
			int val = pq.top().second;
			int d = pq.top().first;
			vector<int> v = intToVector(val);
			pq.pop();
			if(dist[val] != d) continue;
			//for(int i = 0; i < 9; i++) cout << v[i] << ' ' ;
			//cout << d << endl;
			int z;
			for(int i = 0; i < 9; i++) if(v[i] == 0) z = i;
			for(int i = 0; i < 4; i++) {
				int j = (z + dir[i]) % 9;
				swap(v[z], v[j]);
				int nv = vectorToInt(v);
				if(!dist.count(nv) || dist[nv] > d + cost[i]) {
					dist[nv] = d + cost[i];
					pq.emplace(d + cost[i], nv);
				}
				swap(v[z], v[j]);
			}
		}
		cout << dist[vectorToInt(e)] << '\n';
	}
}