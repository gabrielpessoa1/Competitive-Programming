#include <bits/stdc++.h>
using namespace std;
 
main() {
	stack<int> st;
	st.push(0);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '<') {
			++i;
			if(s[i] == '/') {
				if(st.top() == 1) i += 3;
				else i += 5;
				st.pop();
			} else if(s[i] == 'U') {
				i += 2;
				st.push(1);
			} else {
				i += 4;
				st.push(-1);
			}
		} else {
			if(st.top() == 1 && s[i] >= 'a' && s[i] <= 'z') s[i] += 'A' - 'a';
			if(st.top() == -1 && s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a' - 'A';
			cout << s[i];
		}
	}
	cout << '\n';	
}