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


struct pos {
	long long x;
	long long y;
};



int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long d;
	cin >> n >> d;
	vector<pos> p(n);
	rep(i, n) {
		cin >> p[i].x >> p[i].y;
	}
	dsu ds(n);
	rep(i, n) {
		rep(j, n) {
			x = p[i].x - p[j].x;
			y = p[i].y - p[j].y;
			if (x * x + y * y <= d * d) {
				ds.unite(i, j);
			}
		}
	}

	rep(i, n) {
		(ds.same(0, i)) ? yes() : no();
	}
}