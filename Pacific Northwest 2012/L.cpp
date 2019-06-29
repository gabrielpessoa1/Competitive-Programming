#include <bits/stdc++.h>
using namespace std;
 
vector<char> vowel = {'a', 'i', 'y', 'e', 'o', 'u'};
vector<char> consonant = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};
 
map<char, char> dic;
main() {
	int offset = 'A' - 'a';
	for(int i = 0; i < vowel.size(); i++) {
		dic[vowel[(i+3)%vowel.size()]] = vowel[i];
		dic[vowel[(i+3)%vowel.size()] + offset] = vowel[i] + offset;
	}
	for(int i = 0; i < consonant.size(); i++) {
		dic[consonant[(i+10)%consonant.size()]] = consonant[i];
		dic[consonant[(i+10)%consonant.size()]+ offset] = consonant[i] + offset;
	}
	string s;
	while(getline(cin, s)) {
		for(char c : s) {
			if(dic.count(c)) cout << dic[c];
			else cout << c;
		}
		cout << '\n';
	}
}