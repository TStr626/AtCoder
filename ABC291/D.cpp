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

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<vector<long long>> a(n, vector<long long>(2));
	rep(i, n) {
		cin >> a[i][0] >> a[i][1];
	}
	vector<vector<long long>> dp(n, vector<long long>(2, 0));
	dp[0][0] = dp[0][1] = 1;
	rep(i, n - 1) {
		rep(j, 2) {
			rep(k, 2) {
				if (a[i][j] != a[i + 1][k]) {
					dp[i + 1][k] += dp[i][j];
					dp[i + 1][k] %= mod;
				}
			}
		}
	}
	/*
	rep(i, n) {
		rep(j, 2) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	ans = (dp[n - 1][0] + dp[n - 1][1]) % mod;
	cout << ans << endl;
}