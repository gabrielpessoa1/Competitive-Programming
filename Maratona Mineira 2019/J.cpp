#include <bits/stdc++.h>
using namespace std;

const int ms = 3e6+5;

int trie[ms][55], z;
string terminal[ms];
int bestNewIdx[ms];
int bestTrieIdx[ms];

int get_id(char c) {
  if(c >= 'a' && c <= 'z') return c - 'a';
  else return 26 + (c - 'A');
}

void insert(string &a, string &b) {
  int cur = 0;
  for(int i = 0; i < (int) a.size(); i++) {
    int id = get_id(a[i]);
    if(trie[cur][id] == -1) {
      memset(trie[z], -1, sizeof trie[z]);
      trie[cur][id] = z++;
    }
    cur = trie[cur][id];
  }
  terminal[cur] = b;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  memset(trie[0], -1, sizeof trie[0]);
  z = 1;
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  for(int i = 0; i < n; i++) {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    insert(a, b);
  }
  getline(cin, s);
  for(int i = s.size() - 1; i >= 0; i--) {
    bestTrieIdx[i] = -1;
    bestNewIdx[i] = -1;
    int curTrie = 0;
    for(int j = i; j < s.size(); j++) {
      int id = get_id(s[j]);
      if(trie[curTrie][id] == -1) break;
      curTrie = trie[curTrie][id];
      if(!terminal[curTrie].empty() && bestNewIdx[j+1] != -1) {
        bestTrieIdx[i] = curTrie;
        bestNewIdx[i] = j+1;
      }
    }
  }
  int idx = 0;
  while(idx < s.size()) {
    cout << terminal[bestTrieIdx[idx]];
    if(bestNewIdx[idx] < (int) s.size()) {
      cout << ' ';
    }
    cout << flush;
    idx = bestNewIdx[idx];
  }
  cout << '\n';
}