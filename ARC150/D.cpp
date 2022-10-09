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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf;
	cin >> n;
	long long u, v;
	vector<long long> p(n), d(n);
	p[0] = -1; d[0] = 1;
	rep(i, n - 1) {
		cin >> p[i + 1];
		p[i + 1]--;
		d[i + 1] = d[p[i + 1]] + 1;
	}
	
	ans = 0;
	vector<long long> sinv(n + 1);
	sinv[0] = 0;
	for (i = 1; i <= n; i++) {
		sinv[i] = (sinv[i - 1] + invmod(i, mod)) % mod;
	}
	rep(i, n) {
		ans = (ans + sinv[d[i]]) % mod;
	}
	cout << ans << endl;
}