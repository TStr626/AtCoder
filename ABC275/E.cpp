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

long long invmod(long long n, long long mod) {
	// mod must be prime
	// n%mod > 0
	// need "powmod"
	return powmod(n, mod - 2, mod);
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m >> k;
	vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));
	dp[0][0] = 1;
	res = invmod(m, mod);
	for (i = 0; i < k; i++) {
		for (j = 0; j < n; j++) {
			for (x = 1; x <= m; x++) {
				if (j + x <= n) {
					cur = j + x;
				}
				else {
					cur = n - ((j + x) - n);
				}
				dp[i + 1][cur] += dp[i][j] * res;
				dp[i + 1][cur] %= mod;
			}
			
		}
		dp[i + 1][n] += dp[i][n];
		dp[i + 1][n] %= mod;
	}
	
	cout << dp[k][n] << endl;
}