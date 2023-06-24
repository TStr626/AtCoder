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
	cin >> n >> m;
	vector<vector<long long>> dp(n, vector<long long>(2, 0));
	dp[0][1] = m; dp[0][0] = 0;
	for (i = 1; i < n; i++) {
		dp[i][0] += dp[i - 1][0] * (m - 2);
		dp[i][0] += dp[i - 1][1] * (m - 1);
		dp[i][0] %= mod;

		dp[i][1] += dp[i - 1][0] * 1;
		dp[i][1] += dp[i - 1][1] * 0;
		dp[i][1] %= mod;
	}
	cout << dp[n - 1][0] << endl;
}