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

long long invmod(long long n, long long mod) {
	// mod must be prime
	// n%mod > 0
	// need "powmod"
	return powmod(n, mod - 2, mod);
}

struct segtree {
	long long siz, i;
	vector<long long> st;
	// zero-indexed
	// input op,e,update before use

	long long op(long long a, long long b) {
		// input operation
		return a + b;
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

vector<int> compress(vector<int> a, int begin_value) {
	// need <map>,<algorithm>
	int i, n = a.size();
	map<int, int> mp;
	auto b = a;
	sort(b.begin(), b.end());
	int cur, res;
	res = b[0] - 1; cur = begin_value - 1;
	for (i = 0; i < n; i++) {
		if (b[i] > res) {
			res = b[i];
			cur++;
			mp[res] = cur;
		}
	}
	for (i = 0; i < n; i++) {
		b[i] = mp[a[i]];
	}
	return b;
}

struct num {
	long long val;
	long long num;
};
bool operator<(num a, num b) {
	return (a.val != b.val) ? (a.val < b.val) : (a.num < b.num);
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<long long> a(n), st(n), c(n), cnt(n);
	vector<num> b(n);
	rep(i, n) {
		cin >> a[i];
		b[i].val = a[i];
		b[i].num = i;
	}
	sort(b.begin(), b.end());
	rep(i, n) {
		st[i] = b[i].val;
		c[b[i].num] = i;
		cnt[i] = 1;
	}

	vector<long long> vans(n);
	segtree sgv(st), sgc(cnt);
	cur = 0;
	rep(i, n) {
		cur = (cur + b[i].val * (2 * i + 1)) % mod;
	}
	vans[n - 1] = (cur * invmod((n * n) % mod, mod)) % mod;
	
	for (i = n - 1; i >= 1; i--) {
		//cout << c[i] << ' ' << sgc.get(0, c[i] + 1) << endl;
		cur = (cur - (a[i] * (sgc.get(0, c[i] + 1) * 2 - 1)) % mod + mod) % mod;
		cur = (cur - (2 * (sgv.get(c[i] + 1, n))) % mod + mod) % mod;
		sgv.update(c[i], 0);
		sgc.update(c[i], 0);
		vans[i - 1] = (cur * invmod((i * i) % mod, mod)) % mod;
	}

	rep(i, n) {
		cout << vans[i] << endl;
	}

}