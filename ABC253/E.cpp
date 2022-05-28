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
	cin >> n >> m >> k;

	vector<vector<long long>> dp(n, vector<long long>(m, 0));
	rep(j, m) {
		dp[0][j] = 1;
	}

	for (i = 0; i < n - 1; i++) {
		vector<long long> s(m + 1, 0);
		rep(j, m) {
			s[j + 1] = (s[j] + dp[i][j]) % mod;
		}

		rep(j, m) {
			
			if (k == 0) {
				x = 1; y = 0;
			}
			else {
				
				x = max(1ll, j + 2 - k);
				y = min(m, j + k);
			}
			//cout << x << y;
			dp[i + 1][j] = (s[m] - (s[y] - s[x - 1]) + mod) % mod;
		}
	}
	ans = 0;
	rep(j, m) {
		ans = (ans + dp[n - 1][j]) % mod;
	}
	cout << ans << endl;
}
