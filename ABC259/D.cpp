#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
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

int main() {
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod;
	cin >> n;
	dsu d(n + 2);
	long long sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	vector<long long> x(n), y(n), r(n);
	rep(i, n) {
		cin >> x[i] >> y[i] >> r[i];
		cur = abs(x[i] - sx) * abs(x[i] - sx) + abs(y[i] - sy) * abs(y[i] - sy);
		if (cur == r[i] * r[i]) {
			d.unite(0, i + 1);
		}
		res = abs(x[i] - tx) * abs(x[i] - tx) + abs(y[i] - ty) * abs(y[i] - ty);
		if (res == r[i] * r[i]) {
			d.unite(i + 1, n + 1);
		}
	}

	rep(i, n) {
		for (j = i + 1; j < n; j++) {
			cur = abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]);
			if (cur <= (r[i] + r[j]) * (r[i] + r[j]) && cur>=(r[i]-r[j])*(r[i]-r[j])) {
				d.unite(i + 1, j + 1);
			}
		}
	}

	if (d.same(0, n + 1)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}