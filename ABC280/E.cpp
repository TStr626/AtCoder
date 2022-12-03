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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long p, pp, mp;
	cin >> n >> p;
	mod = 998244353;
	pp = (p * invmod(100, mod)) % mod;
	mp = (1 - pp + mod) % mod;
	vector<long long> dp(n + 1);
	dp[0] = 0; dp[1] = 1;
	for (i = 2; i <= n; i++) {
		dp[i] = 1 + pp * dp[i - 2] + mp * dp[i - 1];
		dp[i] %= mod;
	}
	cout << dp[n] << endl;
}