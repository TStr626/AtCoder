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

struct combmod {
	// need "powmod", "invmod"
	long long mod;
	vector<long long> frac, fracinv;

	combmod(long long _n, long long _mod) : frac(_n + 1), fracinv(_n + 1) {
		mod = _mod;
		frac[0] = fracinv[0] = 1;
		for (int i = 1; i <= _n; i++) {
			frac[i] = (frac[i - 1] * i) % mod;
		}
		for (int i = 1; i <= _n; i++) {
			fracinv[i] = invmod(frac[i], mod);
		}
	}

	long long perm(long long n, long long m) {
		if (n < 0 || m < 0 || n < m) {
			return 0;
		}
		return (frac[n] * fracinv[n - m]) % mod;
	}

	long long comb(long long n, long long m) {
		if (n < 0 || m < 0 || n < m) {
			return 0;
		}
		return  (((frac[n] * fracinv[m]) % mod) * fracinv[n - m]) % mod;
	}
};


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> k;
	set<long long> st;
	rep(i, n) {
		cin >> x;
		st.insert(x);
	}

	combmod cb(400010, mod);
	ans = 0; res = k; i = 0;
	while (res > 0) {
		cur = cb.comb(res + i - 1, i);
		//cout << cur << endl;
		ans = (ans + cur) % mod;
		if (st.count(i) == 0) {
			res--;
		}
		i++;
	}
	cout << ans << endl;
}
