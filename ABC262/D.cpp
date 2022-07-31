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
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<long long> a(n), r(n);
	rep(i, n) {
		cin >> a[i];
	}

	ans = 0;
	for (res = 1; res <= n; res++) {
		rep(i, n) {
			r[i] = a[i] % res;
		}

		vector<vector<long long>> dp(res + 1, vector<long long>(res, 0));
		dp[0][0] = 1;
		rep(i, n) {
			for (j = res-1; j >= 0; j--) {
				for (k = 0; k < res; k++) {
					dp[j + 1][(k + r[i]) % res] += dp[j][k];
					dp[j + 1][(k + r[i]) % res] %= mod;
				}
			}
		}
		ans += dp[res][0];
		ans %= mod;
	}
	cout << ans << endl;
	
}