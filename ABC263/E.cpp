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
	cin >> n;
	vector<long long> a(n - 1), p(n + 1);
	rep(i, n - 1) {
		cin >> a[i];
	}
	reverse(a.begin(), a.end());

	p[0] = 0;
	rep(i, n - 1) {
		cur = (p[i + 1] - p[i + 1 - a[i]] + mod) % mod;
		cur += a[i] + 1;
		cur = (cur * invmod(a[i], mod)) % mod;
		p[i + 2] = (p[i + 1] + cur) % mod;
	}
	/*
	rep(i, n) {
		if (i) cout << ' ';
		cout << p[i];
	}
	*/
	cout << (p[n] - p[n - 1] + mod) % mod << endl;
}