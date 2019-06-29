#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
bool vis[10];
 
main() {
	int n;
	while(cin >> n) {
		int cur = 0;
		memset(vis, 0, sizeof vis);
		int c = 0;
		int k = 0;
		while(c < 10) {
			k++;
			cur += n;
			int temp = cur;
			while(temp > 0) {
				c += !vis[temp%10];
				vis[temp%10] = 1;
				temp /= 10;
			}
		}
		cout << k << '\n';
	}
}