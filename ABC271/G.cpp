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
// WIP
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
	long long n, m, i, j, k, x, y, h, w, ans, cur, res, jud, mod = 998244353, inf;
	string s;
	cin >> n >> x >> y >> s;
	s = s + s;

	vector<vector<vector<long long>>> dp(61, vector<vector<long long>>(24, vector<long long>(24, 0)));
	vector<long long> t(24, 0), t2(24, 0);
	long long inv100 = invmod(100, mod), b;
	cur = 1;
	rep(i, 24) {
		cur = 1;
		for (res = 1; res <= 24; res++) {
			j = (i + res) % 24;

			if (s[j] == 'T') {
				dp[0][i][j] = (((cur * inv100) % mod) * x) % mod;
				cur = (((cur * inv100) % mod) * (100 - x)) % mod;
			}
			else {
				dp[0][i][j] = (((cur * inv100) % mod) * y) % mod;
				cur = (((cur * inv100) % mod) * (100 - y)) % mod;
			}
		}

		for (j = 0; j < 24; j++) {
			dp[0][i][j] = (dp[0][i][j] * invmod(1 + mod - cur, mod)) % mod;
		}
		
	}

	rep(b, 60) {
		rep(i, 24) {
			rep(j, 24) {
				dp[b + 1][i][j] = 0;
				rep(k, 24) {
					dp[b + 1][i][j] += (dp[b][i][k] * dp[b][k][j]) % mod;
				}
				dp[b + 1][i][j] %= mod;
			}
		}
	}
	
	t[23] = 1; b = 0;
	while (n > 0) {
		if (n % 2) {
			rep(j, 24) {
				t2[j] = 0;
				rep(i, 24) {
					t2[j] += (t[i] * dp[b][i][j]) % mod;
				}
				t2[j] %= mod;
			}
			
			rep(j, 24) {
				t[j] = t2[j];
			}
		}
		b++;
		n /= 2;
	}

	ans = 0;
	rep(i, 24) {
		if (s[i] == 'A') {
			ans += t[i];
		}
	}
	cout << ans % mod << endl;
	
}