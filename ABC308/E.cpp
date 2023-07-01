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


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	string s;
	cin >> s;
	vector<long long> ss(n);
	rep(i, n) {
		if (s[i] == 'M') {
			ss[i] = 0;
		}
		else if (s[i] == 'E') {
			ss[i] = 1;
		}
		else {
			ss[i] = 2;
		}
	}
	vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(4, vector<long long>(1 << 3, 0)));
	dp[0][0][0] = 1;
	ans = 0;
	rep(i, n) {
		rep(j, 3) {
			rep(k, (1 << 3)) {
				dp[i + 1][j][k] += dp[i][j][k];
				if (ss[i] == j) {
					dp[i + 1][j + 1][k | (1 << a[i])] += dp[i][j][k];
				}
			}
		}
		rep(k, (1 << 3)) {
			if ((k & 1) == 0) {
				cur = 0;
			}
			else if ((k & 2) == 0) {
				cur = 1;
			}
			else if ((k & 4) == 0) {
				cur = 2;
			}
			else {
				cur = 3;
			}
			ans += dp[i + 1][3][k] * cur;
		}
	}
	cout << ans << endl;
}