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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 1000000000;
	cin >> n >> k;
	vector<long long> a(k);
	rep(i, k) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	long long j1, j2;
	vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
	
	

	rep(i, n + 1) {
		dp[i][0] = -inf;
		dp[i][1] = +inf;
	}
	dp[0][0] = 0;
	dp[0][1] = 0;

	for (j1 = 1; j1 <= n; j1++) {
		for (i = 0; i < k && a[i] <= j1; i++) {
			dp[j1][0] = max(dp[j1][0], dp[j1 - a[i]][1] + a[i]);
			dp[j1][1] = min(dp[j1][1], dp[j1 - a[i]][0] - a[i]);
		}
	}
	ans = n - (n - dp[n][0]) / 2;
	cout << ans << endl;
	//cout << dp[n][0] << endl;
}