// BSUIR Semifinal 2016-2017
// F - A+B
// https://codeforces.com/group/yc7Yxny414/contest/102134/problem/F

#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef struct item * pitem;
struct item {
	int prior, value, cnt;
  int carry[2];
	pitem l, r;
};

int cnt (pitem it) { return it ? it->cnt : 0; };

int get_carry (pitem it, int c) {
  if (!it) return c;
  else return it->carry[c];
}

void upd_cnt (pitem it) {
	if (it) {
    it->cnt = cnt(it->l) + cnt(it->r) + 1;
    for(int i = 0; i < 2; i++) {
      it->carry[i] = get_carry(it->l, (it->value + get_carry(it->r, i))/10);
    }
  }
}


void merge (pitem & t, pitem l, pitem r) {
	if (!l || !r) t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
	upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key) {
	if (!t) return void( l = r = 0 );
	int cur_key = cnt(t->l);
	if (key <= cur_key)
		split (t->l, l, t->l, key),  r = t;
	else
		split (t->r, t->r, r, key - (1 + cnt(t->l))),  l = t;
	upd_cnt (t);
}

pitem treap;

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  treap = new item();
  treap->prior = rng();
  treap->value = 0;
  upd_cnt(treap);
  for(int i = 0; i < n; i++) {
    int type;
    cin >> type;
    if(type == 1) {
      int k, a, b;
      cin >> k >> a >> b;
      pitem l, r;
      pitem newItem = new item();
      newItem->prior = rng();
      newItem->value = a+b;
      upd_cnt(newItem);
      split(treap, l, r, k);
      merge(treap, l, newItem);
      merge(treap, treap, r);
    } else if(type == 2) {
      int k;
      cin >> k;
      k--;
      pitem l, m, r;
      split(treap, l, r, k);
      split(r, m, r, 1);
      merge(treap, l, r);
      if(m) delete(m);
    } else {
      int k;
      cin >> k;
      k--;
      if(get_carry(treap, 0)) {
        k--;
      }
      if(k == -1) {
        cout << 1 << '\n';
      } else if(k >= cnt(treap)) {
        cout << -1 << '\n';
      } else {
        pitem l, m, r;
        split(treap, l, r, k);
        split(r, m, r, 1);
        cout << (m->value + get_carry(r, 0))%10 << '\n';
        merge(r, m, r);
        merge(treap, l, r);
      }
    }
  }
}