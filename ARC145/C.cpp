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

long long combmod(long long n, long long m, long long mod) {
	if (n < 0 || m < 0 || n < m) {
		return 0ll;
	}
	long long i, cur1, cur2;
	cur1 = 1;
	for (i = 0; i < m; i++) {
		cur1 = (cur1 * (n - i)) % mod;
	}
	cur2 = 1;
	for (i = 1; i <= m; i++) {
		cur2 = (cur2 * i) % mod;
	}
	return (cur1 * invmod(cur2, mod)) % mod;
}

long long factorialmod(long long n, long long mod) {
	long long ans, i;
	ans = 1;
	if (n >= mod) {
		return 0ll;
	}
	for (i = 2; i <= n; i++) {
		ans = (ans * i) % mod;
	}
	return ans;
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	ans = combmod(2 * n, n, mod);
	ans = (ans * invmod(n + 1, mod)) % mod;
	//cout << ans << endl;
	ans = (ans * factorialmod(n, mod)) % mod;
	ans = (ans * powmod(2, n, mod)) % mod;
	cout << ans << endl;
	
}