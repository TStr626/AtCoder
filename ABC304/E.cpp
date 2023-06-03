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
bool operator<(pos a, pos b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.y < b.y;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	
	dsu d(n);
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		d.unite(x, y);
	}
	
	cin >> k;
	set<pos> st;
	rep(i, k) {
		cin >> x >> y;
		x--; y--;
		cur = d.root(x); res = d.root(y);
		st.insert({ cur,res });
		st.insert({ res,cur });
	}

	long long query;
	cin >> query;
	rep(i, query) {
		cin >> x >> y;
		x--; y--;
		if (st.count({ d.root(x),d.root(y) })) {
			no();
		}
		else {
			yes();
		}
	}
	
}