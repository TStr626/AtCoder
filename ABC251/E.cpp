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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf = 1000000000000000000ll;
	cin >> n;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}

	vector<vector<long long>> dp(n + 1, vector<long long>(2, inf));
	
	ans = inf;
	// select a[0]
	dp[0][0] = 0; dp[0][1] = 0; dp[1][1] = a[0]; dp[1][0] = inf;
	for (i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a[i - 1];
	}
	ans = min(dp[n][0], dp[n][1]);
	
	// not select a[0]
	dp[0][0] = 0; dp[0][1] = 0; dp[1][1] = inf; dp[1][0] = 0;
	for (i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a[i - 1];
	}
	ans = min(ans, dp[n][1]);

	cout << ans << endl;
}
