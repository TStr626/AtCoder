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

long long powmod(long long n, long long m, long long mod) {
	// mod>0
	long long i, ans, cur, res;
	if (n % mod == 0) {
		return 0;
	}
	ans = 1; cur = n % mod; res = m;
	while (res > 0) {
		if (res % 2 == 1) {
			ans = (ans * cur) % mod;
		}
		cur = (cur * cur) % mod;
		res /= 2;
	}
	return ans;
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

struct node {
	long long x;
	long long y;
	long long c;
};

bool operator<(node a, node b) {
	return a.c > b.c;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> m;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	mod = m;
	vector<vector<long long>> mat(n, vector<long long>(n));
	rep(i, n) {
		for (j = i + 1; j < n; j++) {
			mat[i][j] = mat[j][i] = (powmod(a[i], a[j], mod) + powmod(a[j], a[i], mod)) % mod;
		}
	}
	/*
	cout << endl;
	rep(i, n) {
		rep(j, n) {
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
	*/


	multiset<node> ms;
	rep(i, n) {
		for (j = i + 1; j < n; j++) {
			ms.insert({ i,j,mat[i][j] });
		}
	}
	ans = 0;
	node nd;
	dsu d(n);
	while(ms.size()) {
		nd = *ms.begin();
		ms.erase(ms.begin());
		if (d.same(nd.x, nd.y)) {
			continue;
		}
		d.unite(nd.x, nd.y);
		ans += nd.c;
	}
	cout << ans << endl;
	
}