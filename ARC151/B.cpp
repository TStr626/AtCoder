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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf;
	cin >> n >> m;
	vector<long long> p(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}

	dsu d(n);
	cur = n - 2;
	ans = 0;
	long long comb2 = ((m * (m - 1)) / 2) % mod;

	rep(i, n) {
		if (d.same(i, p[i])) {
			// pass
		}
		else {
			ans += powmod(m, cur, mod);
			ans %= mod;
			d.unite(i, p[i]);
			cur--;
		}
	}
	ans = (ans * comb2) % mod;
	cout << ans << endl;
	
}