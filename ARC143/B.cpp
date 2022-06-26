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
/*
long long permmod(long long n, long long m, long long mod) {
	if (n < 0 || m < 0 || n < m) {
		return 0ll;
	}
	long long i, cur1;
	cur1 = 1;
	for (i = 0; i < m; i++) {
		cur1 = (cur1 * (n - i)) % mod;
	}
	return cur1;
}
*/

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	vector<vector<long long>> a(n, vector<long long>(n));

	vector<long long> permmod(n * n + 1), combmod(n * n + 1, 0);
	permmod[0] = 0; permmod[1] = 1;
	for (i = 2; i <= n * n; i++) {
		permmod[i] = (permmod[i - 1] * i) % mod;
	}

	combmod[n - 1] = 1;
	for (i = n; i <= n * n; i++) {
		combmod[i] = (combmod[i - 1] * i) % mod;
		combmod[i] = (combmod[i] * (invmod(i - (n - 1), mod))) % mod;
	}

	ans = permmod[n * n];
	for (i = n; i <= n * n - (n - 1); i++) {
		cur = combmod[i - 1] * permmod[n - 1] % mod;
		res = combmod[n * n - i] * permmod[n - 1] % mod;
		cur = (cur * res) % mod;
		cur = (cur * permmod[n * n - (2 * n - 1)]) % mod;
		cur = (cur * n * n) % mod;
		ans = (ans - cur + mod) % mod;
	}
	
	cout << ans << endl;

}