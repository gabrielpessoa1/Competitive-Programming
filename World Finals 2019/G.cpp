// World Finals 2019
// G - First of Her Name
// https://open.kattis.com/problems/firstofhername

#include <bits/stdc++.h>
using namespace std;

const int ms = 1e6+5;

int par[ms];
int qnt[ms];
char letter[ms];
char str[ms];
int trie[ms][30], z;
int posInTrie[ms];
int queryToTrie[ms];
int fail[ms];
queue<int> q;
vector<int> revOrder;

int add(int n) {
    int cur = 0;
    for(int i = n - 1; i >= 0; i--) {
        int id = str[i] - 'A';
        if(trie[cur][id] == -1) {
            memset(trie[z], -1, sizeof trie[z]);
            trie[cur][id] = z++;
        }
        cur = trie[cur][id];
    }
    return cur;
}

void buildFailure() {
    q.push(0);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int pos = 0; pos < 26; pos++) {
            int &v = trie[node][pos];
            int f = node == 0 ? 0 : trie[fail[node]][pos];
            if(v == -1) {
                v = f;
            } else {
                fail[v] = f;
                q.push(v);
                revOrder.push_back(v);
            }
        }
    }
}

int main() {
    memset(trie[0], -1, sizeof trie[0]);
    z = 1;
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf(" %c %d\n", &letter[i], &par[i]);
    }
    for(int i = 1; i <= k; i++) {
        scanf("%s", &str);
        queryToTrie[i] = add(strlen(str));
    }
    buildFailure();
    for(int i = 1; i <= n; i++) {
        posInTrie[i] = trie[posInTrie[par[i]]][letter[i] - 'A'];
        qnt[posInTrie[i]]++;
    }
    reverse(revOrder.begin(), revOrder.end());
    for(int i : revOrder) {
        qnt[fail[i]] += qnt[i];
    }
    for(int i = 1; i <= k; i++) {
        printf("%d\n", qnt[queryToTrie[i]]);
    }
    return 0;
}
