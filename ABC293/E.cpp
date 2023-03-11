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

long long totient(long long n) {
	long long ans, cur, i;
	ans = n; cur = n;

	for (i = 2; i * i <= cur; i++) {
		if (cur % i > 0) {
			continue;
		}

		ans = (ans / i) * (i - 1);
		while (cur % i == 0) {
			cur /= i;
		}
	}
	if (cur > 1) {
		ans = (ans / cur) * (cur - 1);
	}

	return ans;
}

long long invmod_gen(long long n, long long mod) {
	// need totient, powmod
	return powmod(n, totient(mod) - 1, mod);
}

long long dfs(long long n, long long m, long long mod) {
	if (m == 1) {
		return 1;
	}
	if (m % 2 == 0) {
		return (dfs(n, m / 2, mod) * (1 + powmod(n, m / 2, mod))) % mod;
	}
	else {
		return (((dfs(n, m / 2, mod) * (1 + powmod(n, m / 2, mod))) % mod) + powmod(n, m - 1, mod)) % mod;
	}
	return 0;
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> x >> m;
	ans = dfs(n, x, m);
	cout << ans % m << endl;
}