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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long t;
	cin >> n >> m >> k;
	k -= n;

	vector<vector<long long>> dp(n, vector<long long>(k+1, 0));
	for (j = 0; j < min(k + 1, m); j++) {
		dp[0][j] = 1;
	}
	for (i = 0; i < n-1; i++) {
		for (j = 0; j <= k; j++) {
			for (t = 0; t < m; t++) {
				if (j + t > k) continue;
				dp[i + 1][j + t] += dp[i][j];
				dp[i + 1][j + t] %= mod;
			}
		}
	}
	/*
	rep(i, n) {
		rep(j, k + 1) {
			cout << dp[i][j];
		}
		cout << endl;
	}
	*/
	ans = 0;
	rep(j, k + 1) {
		ans=(ans+dp[n - 1][j])%mod;
	}
	cout << ans << endl;
}