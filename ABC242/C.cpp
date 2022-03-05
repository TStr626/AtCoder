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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	mod = 998244353;
	vector<vector<long long>> dp(n + 1, vector<long long>(9,0));
	rep(j, 9) {
		dp[1][j] = 1;
	}
	rep(i, n-1) {
		rep(j, 9) {
			if (j > 0) {
				dp[i + 2][j - 1] += dp[i + 1][j];
				dp[i + 2][j - 1] %= mod;
			}
			dp[i + 2][j] += dp[i + 1][j];
			dp[i + 2][j] %= mod;
			if (j < 8) {
				dp[i + 2][j + 1] += dp[i + 1][j];
				dp[i + 2][j + 1] %= mod;
			}
		}
	}
	ans = 0;
	rep(j, 9) {
		ans += dp[n][j];
		ans %= mod;
	}
	cout << ans << endl;
}