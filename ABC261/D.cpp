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
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod;
	cin >> n >> m;
	vector<long long> x(n);
	rep(i, n) {
		cin >> x[i];
	}
	vector<long long> y(n, 0);
	rep(i, m) {
		cin >> j;
		cin >> y[j - 1];
	}
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
	for (i = 1; i <= n; i++) {
		cur = 0;
		for (j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + x[i - 1] + y[j - 1];
			cur = max(cur, dp[i - 1][j - 1]);
		}
		dp[i][0] = cur;
	}
	
	ans = 0;
	rep(j, n + 1) {
		ans = max(ans, dp[n][j]);
	}
	cout << ans << endl;
}