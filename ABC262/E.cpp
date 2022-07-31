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



int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m >> k;
	vector<long long> v(n, 0);
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		v[x] ^= 1; v[y] ^= 1;
	}
	long long odd, eve;
	odd = 0; eve = 0;
	rep(i, n) {
		if (v[i]) {
			odd++;
		}
		else {
			eve++;
		}
	}

	//cout << odd << eve << endl;
	long long j1, j2;
	vector<long long> combodd(k + 1,0), combeve(k + 1,0);
	combodd[0] = 1; combeve[0] = 1;
	rep(i, k) {
		combodd[i + 1] = (combodd[i] * invmod(i + 1, mod)) % mod;
		combodd[i + 1] = (combodd[i + 1] * ((odd + 1) - (i + 1))) % mod;
		combeve[i + 1] = (combeve[i] * invmod(i + 1, mod)) % mod;
		combeve[i + 1] = (combeve[i + 1] * ((eve + 1) - (i + 1))) % mod;
	}
	ans = 0;
	for (i = 0; i <= k; i += 2) {
		ans = (ans + combodd[i] * combeve[k - i]) % mod;
	}
	cout << ans << endl;
	
}