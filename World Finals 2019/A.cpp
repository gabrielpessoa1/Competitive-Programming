// World Finals 2019
// A - Azulejos
// https://open.kattis.com/problems/azulejos

#include <bits/stdc++.h>
using namespace std;

const int ms = 5e5+5;
const int inf = 0x3f3f3f3f;

#define price first.first
#define height first.second
#define idx second

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

iii p[2][ms];
set<ii> my_set[2];
set<ii> to_clone;
int ans[2][ms];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &p[i][j].price);
			p[i][j].idx = j+1;
		}
		for(int j = 0; j < n; j++) {
			scanf("%d", &p[i][j].height);
		}
		sort(p[i], p[i]+n);
	}
	int j[2] = {-1, -1};
	int i = 0;
	to_clone.insert(ii(-1, -1));
	to_clone.insert(ii(inf, inf));
	while(i < n) {
		for(int k = 0; k < 2; k++) {
			if(j[k] < i) {
				my_set[k] = to_clone;
				j[k]++;
				while(p[k][j[k]].price == p[k][j[k]+1].price) j[k]++;
				for(int x = i; x <= j[k]; x++) {
					my_set[k].insert(ii(p[k][x].height, p[k][x].idx));
				}
			}
		}
		int lo = 0, hi = 1;
		if(j[0] > j[1]) swap(lo, hi);
		for(auto e : my_set[lo]) {
			if(e.first != -1 && e.first != inf) {
				ii y;
				if(lo == 0) {
					auto it = my_set[hi].lower_bound(ii(e.first, -1));
					it--;
					y = *it;
					my_set[hi].erase(it);
				} else {
					auto it = my_set[hi].lower_bound(ii(e.first, inf));
					y = *it;
					my_set[hi].erase(it);
				}
				if(y.first == -1 || y.first == inf) {
					cout << "impossible\n";
					return 0;
				}
				ans[lo][i] = e.second;
				ans[hi][i] = y.second;
				i++;
			}
		}
	}
	for(int k = 0; k < 2; k++) {
		for(int i = 0; i < n; i++) {
			printf("%d%c", ans[k][i], (i == n -1) ? '\n' : ' ');
		}
	}
}