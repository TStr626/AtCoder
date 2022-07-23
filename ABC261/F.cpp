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

struct BIT {
	long long siz;
	vector<long long> a;

	BIT(long long n) : siz(n), a(n + 1) {}
	// one_indexed

	void add(long long i, long long x) {
		// 1<=i<=n
		for (long long k = i; k <= siz; k += (k & -k)) {
			a[k] += x;
		}
	}

	long long sum(long long i, long long j) {
		// a[i]+...+a[j]
		return sum_sub(j) - sum_sub(i - 1);
	}

	long long sum_sub(long long i) {
		// a[1]+...+a[i]
		if (i == 0) return 0;

		long long s = 0;
		for (long long k = i; k > 0; k -= (k & -k)) {
			s += a[k];
		}
		return s;
	}
};

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



long long inverseCount(vector<long long> v) {
	if (v.size() == 0) {
		return 0;
	}
	vector<long long> vc = compress(v, 1);
	
	long long n, i, ans;
	n = v.size();
	/*
	rep(i, n) {
		cout << vc[i];
	}
	cout << endl;
	*/
	ans = 0;
	BIT b(n + 1);
	rep(i, n) {
		ans += i-b.sum(0, vc[i] + 1);
		b.add(vc[i] + 1, 1);
	}
	return ans;
}

int main() {
	long long n, m, i, j, k, h, w, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<long long> c(n), x(n);
	vector<vector<long long>> g(n, vector<long long>(0));
	rep(i, n) {
		cin >> c[i];
		c[i]--;
	}
	rep(i, n) {
		cin >> x[i];
		g[c[i]].push_back(x[i]);
	}
	ans = inverseCount(x);
	rep(i, n) {
		//cout << ans << endl;
		ans -= inverseCount(g[i]);
	}
	cout << ans << endl;
}