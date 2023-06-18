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

vector<long long> compress(vector<long long> a, long long begin_value) {
	// need <map>,<algorithm>
	long long i, n = a.size();
	map<long long, long long> mp;
	auto b = a;
	sort(b.begin(), b.end());
	long long cur, res;
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


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	vector<vector<long long>> a(n, vector<long long>(m));
	vector<long long> b(n * m);
	rep(i, n) {
		rep(j, m) {
			cin >> b[i * m + j];
		}
	}
	auto c = compress(b, 0);
	vector<long long> d(n* m);
	rep(i, n) {
		rep(j, m) {
			a[i][j] = c[i * m + j];
			d[c[i * m + j]] = i;
		}
		sort(a[i].begin(), a[i].end());
	}

	ans = 0;
	segtree sg(vector<long long>(n * m, 0));
	k = n - 1;
	for (i = k; i >= 0; i--) {
		rep(j, m) {
			ans += (k - i) * (j + 1) + sg.get(0, a[i][j]);
		}
		rep(j, m) {
			sg.update(a[i][j], 1);
		}
	}
	cout << ans << endl;
}