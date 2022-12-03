#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)

struct dsu {
	// disjoint set : union find
	vector<int> p;

	dsu() {}
	dsu(int n) : p(n) {
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
	}

	int root(int a) {
		if (p[a] == a) {
			return a;
		}
		else {
			return p[a] = root(p[a]);
		}
	}

	void unite(int a, int b) {
		int x = root(a), y = root(b);
		if (x == y) {
			return;
		}
		else {
			p[x] = y; return;
		}
	}

	bool same(int a, int b) {
		return root(a) == root(b);
	}

};

struct wdsu {
	// weighed disjoint set : union find
	vector<int> p;
	vector<long long> w;

	wdsu() {}
	wdsu(int n) : p(n), w(n) {
		for (int i = 0; i < n; i++) {
			p[i] = i;
			w[i] = 0;
		}
	}

	int root(int a) {
		if (p[a] == a) {
			return a;
		}
		else {
			int r = root(p[a]);
			w[a] += w[p[a]];
			return p[a] = r;
		}
	}

	long long weight(int a) {
		root(a);
		return w[a];
	}
	long long diff(int a, int b) {
		return weight(b) - weight(a);
	}

	bool unite(int a, int b, long long d) {
		// it returns false iff it conflicts
		int x = root(a), y = root(b);
		if (x == y) {
			return d == diff(a, b);
		}
		else {
			d = d + w[a] - w[b];
			p[y] = x;
			w[y] = d;
			return true;
		}
	}

	bool same(int a, int b) {
		return root(a) == root(b);
	}

};

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long query, c;
	cin >> n >> m >> query;
	//vector<vector<edge>> g(n, vector<edge>(0));
	dsu d(n + 1);
	wdsu wd(n);
	rep(i, m) {
		cin >> x >> y >> c;
		x--; y--;
		if (wd.unite(x, y, c) == false) {
			d.unite(x, n);
		}
		d.unite(x, y);
	}

	while (query--) {
		cin >> x >> y;
		x--; y--;
		if (d.same(x, y) == false) {
			cout << "nan" << endl;
			continue;
		}
		if (d.same(x, n) == true) {
			cout << "inf" << endl;
			continue;
		}
		cout << wd.diff(x, y) << endl;
	}
}