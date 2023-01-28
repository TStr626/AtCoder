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
	vector<int> siz;

	dsu(int n) : p(n), siz(n) {
		for (int i = 0; i < n; i++) {
			p[i] = i;
			siz[i] = 1;
		}
	}

	int root(int a) {
		if (p[a] == a) {
			return a;
		}
		return p[a] = root(p[a]);
	}

	void unite(int a, int b) {
		int x = root(min(a, b)), y = root(max(a, b));
		if (x == y) {
			return;
		}
		p[y] = x;
		siz[x] += siz[y];
		return;
	}

	bool same(int a, int b) {
		return root(a) == root(b);
	}

	int size(int a) {
		return siz[root(a)];
	}

};

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> m;
	vector<long long> d(n);
	dsu ds(n);
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		d[x]++; d[y]++;
		ds.unite(x, y);
	}

	// edge count
	if (m != n - 1) {
		cout << "No" << endl;
		return 0;
	}
	// connected
	rep(i, n) {
		if (ds.same(0, i) == false) {
			cout << "No" << endl;
			return 0;
		}
	}
	// dimension
	sort(d.begin(), d.end());
	if (d[0] == 1 && d[1] == 1 && (n == 2 || d[2] == 2)) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	
}