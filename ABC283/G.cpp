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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long l, r;
	cin >> n >> l >> r;
	l--; r--;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<long long> base(0);
	rep(i, n) {
		cur = a[i];
		rep(j, base.size()) {
			cur = min(cur, cur ^ base[j]);
		}
		if (cur > 0) {
			base.push_back(cur);
		}
	}
	
	sort(base.begin(), base.end());
	/*
	for (auto v : base) {
		cout << v << ' ';
	}
	cout << endl;
	*/

	rep(i, base.size()) {
		for (j = i - 1; j >= 0; j--) {
			base[i] = min(base[i], base[i] ^ base[j]);
		}
	}
	sort(base.begin(), base.end());
	/*
	for (auto v : base) {
		cout << v << ' ';
	}
	cout << endl;
	*/
	for (i = l; i <= r; i++) {
		ans = 0; cur = i;
		rep(j, base.size()) {
			if (cur & 1) {
				ans ^= base[j];
			}
			cur >>= 1;
		}
		if (i > l) {
			cout << ' ';
		}
		cout << ans;
	}
	cout << endl;
}