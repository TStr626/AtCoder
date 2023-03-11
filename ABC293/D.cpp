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
void yes() {
	cout << "Yes" << endl;
}
void no() {
	cout << "No" << endl;
}
void vec_h(vector<long long> a) {
	int n = a.size(), i;
	rep(i, n) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
}
void vec_v(vector<long long> a) {
	for (auto c : a) {
		cout << c << endl;
	}
}

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}

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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	char c, e;
	dsu d(n);
	cur = n; res = 0;
	rep(i, m) {
		cin >> x >> c >> y >> e;
		x--; y--;
		if (d.same(x, y)) {
			cur--; res++;
		}
		else {
			d.unite(x, y);
			cur--;
		}
	}
	cout << res << ' ' << cur << endl;
}