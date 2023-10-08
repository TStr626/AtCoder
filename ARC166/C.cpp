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


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	n = 1000000;
	vector<long long> dp(2 * n + 2), ddp(2 * n + 1);
	dp[0] = dp[1] = 1; dp[2] = 2;
	for (i = 3; i <= 2 * n + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= mod;
	}
	ddp[0] = ddp[1] = 1;
	for (i = 1; i <= n; i++) {
		ddp[2 * i] = ddp[2 * (i - 1)] * ((dp[2 * i] * dp[2 * i]) % mod);
		ddp[2 * i] %= mod;
	}

	long long test;
	cin >> test;
	while (test--) {
		cin >> h >> w;
		if (h > w) {
			swap(h, w);
		}
		ans = ddp[2 * h];
		ans *= powmod(dp[2 * h + 1], w - h, mod);
		ans %= mod;
		cout << ans << endl;
	}
}