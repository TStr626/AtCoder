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

long long inversion(vector<long long> a) {
	// need BIT
	// 0 <= a[i] < a.size(), compress in advance
	long long n = a.size(), i, ans;
	BIT b(n + 1);

	ans = 0;
	for (i = 0; i < n; i++) {
		ans += i - b.sum(1, a[i] + 1);
		b.add(a[i] + 1, 1);
	}
	return ans;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<long long> a(n), b(n), c(n), d(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
		c[i] = a[i];
	}
	rep(j, n) {
		cin >> b[j];
		b[j]--;
		d[j] = b[j];
	}

	// has same value?
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	rep(i, n) {
		if (c[i] != d[i]) {
			no();
			return 0;
		}
	}
	// has any duplicate?
	rep(i, n - 1) {
		if (c[i] == c[i + 1]) {
			yes();
			return 0;
		}
	}
	// parity of inversion count
	if (inversion(a) % 2 == inversion(b) % 2) {
		yes();
	}
	else {
		no();
	}
}