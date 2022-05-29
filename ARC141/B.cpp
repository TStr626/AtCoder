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

long long bidigit(long long n) {
	long long ans = 1, cur = n;
	while (cur >= 2) {
		cur /= 2;
		ans++;
	}
	return ans;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	long long b;
	b = bidigit(m);
	if (n > b) {
		cout << 0 << endl;
		return 0;
	}

	vector<long long> cnt(b + 1, 0);
	for (i = 1; i <= b; i++) {
		cnt[i] = max(0ll, (min((1ll << i) - 1, m) - ((1ll << (i - 1)) - 1)));
		cnt[i] %= mod;
	}
	/*
	rep(i, b+1) {
		cout << cnt[i] << endl;
	}
	*/

	vector<vector<long long>> dp(n + 1, vector<long long>(b + 1, 0));
	dp[0][0] = 1;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= b; j++) {
			for (k = j + 1; k <= b; k++) {
				dp[i + 1][k] = (dp[i + 1][k] + (dp[i][j] * cnt[k])) % mod;
			}
		}
	}
	/*
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= b; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	*/

	ans = 0;
	for (j = 1; j <= b; j++) {
		ans = (ans + dp[n][j]) % mod;
	}
	cout << ans << endl;

}