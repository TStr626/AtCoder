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
void yes() {
	cout << "Yes" << endl;
}
void no() {
	cout << "No" << endl;
}
void vec_h(vector<long long> a) {
	int n = a.size(), i;
	rep(i, n) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
}
void vec_v(vector<long long> a) {
	for (auto c : a) {
		cout << c << endl;
	}
}

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
	long long a, b, p, q, invp, invq;
	cin >> n >> a >> b >> p >> q;
	invp = invmod(p, mod);
	invq = invmod(q, mod);
	vector<vector<long long>> da(n, vector<long long>(n + 1, 0)), db(n, vector<long long>(n + 1, 0));
	da[0][a] = 1; db[0][b] = 1;
	rep(i, n - 1) {
		rep(j, n) {
			for (k = 1; k <= p; k++) {
				da[i + 1][min(j + k, n)] += (da[i][j] * invp) % mod;
				da[i + 1][min(j + k, n)] %= mod;
			}
			for (k = 1; k <= q; k++) {
				db[i + 1][min(j + k, n)] += (db[i][j] * invq) % mod;
				db[i + 1][min(j + k, n)] %= mod;
			}
		}
	}
	ans = 0; cur = 1;
	rep(i, n) {
		ans = (ans + (cur * da[i][n]) % mod) % mod;
		cur = (cur + mod - db[i][n]) % mod;
	}
	cout << ans << endl;
}