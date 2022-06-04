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

long long gcd(long long a, long long b) {
	if (a == 0 || b == 0) {
		return max(a, b);
	}

	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}

struct segtree {
	long long siz, i;
	vector<long long> st;
	// zero-indexed
	// input op,e,update before use

	long long op(long long a, long long b) {
		// input operation
		return gcd(a, b);
	}

	long long e() {
		// input neutral element
		return 0;
	}

	segtree(vector<long long> v) {
		siz = 1;
		while (siz < v.size()) {
			siz *= 2;
		}
		st.resize(2 * siz - 1, e());
		for (i = 0; i < v.size(); i++) {
			st[i + siz - 1] = v[i];
		}
		for (i = siz - 2; i >= 0; i--) {
			st[i] = op(st[2 * i + 1], st[2 * i + 2]);
		}
	}

	void update(int p, long long x) {
		p += (siz - 1);
		// set update 
		st[p] = x;
		while (p > 0) {
			p = (p - 1) / 2;
			st[p] = op(st[2 * p + 1], st[2 * p + 2]);
		}
	}

	long long get(int l, int r) {
		// [l,r)
		return getdfs(l, r, 0, 0, siz);
	}
	long long getdfs(int l, int r, int k, int a, int b) {
		// k is current node
		// [a,b) is current section 

		// no intersection
		if (b <= l || r <= a) {
			return e();
		}

		// completely included
		if (l <= a && b <= r) {
			return st[k];
		}

		// otherwise
		long long curl = getdfs(l, r, 2 * k + 1, a, (a + b) / 2);
		long long curr = getdfs(l, r, 2 * k + 2, (a + b) / 2, b);
		return op(curl, curr);
	}

};

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long query, l, r;
	cin >> n >> query;
	vector<long long> a(n), b(n), da(n - 1), db(n - 1);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}

	rep(i, n-1) {
		da[i] = abs(a[i + 1] - a[i]);
		db[i] = abs(b[i + 1] - b[i]);
	}

	segtree sega(da), segb(db);
	long long xl, xr, yl, yr;
	while (query--) {
		cin >> xl >> xr >> yl >> yr;
		xl--; xr--; yl--; yr--;
		//cout << sega.get(xl, xr) << endl;
		cur = gcd(sega.get(xl, xr), segb.get(yl, yr));
		ans = gcd(cur, a[xl] + b[yl]);
		cout << ans << endl;
	}
	
}
