#include <bits/stdc++.h>
using namespace std;
 
main() {
	string s;
	int k;
	cin >> s >> k;
	string p;
	for(char c : s) {
		while(!p.empty() && p[p.size()-1] < c && k > 0) {
			p.pop_back();
			k--;
		}
		p.push_back(c);
	}
	while(k > 0) {
		p.pop_back();
		k--;
	}
	cout << p << '\n';	
}