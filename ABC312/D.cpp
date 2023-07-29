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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	string s;
	cin >> s;
	n = s.size();
	if (n % 2) {
		cout << 0 << endl;
		return 0;
	}
	m = n / 2;
	vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
	dp[0][0] = 1;
	rep(i, n) {
		if (s[i] == '(' || s[i] == '?') {
			rep(j, m) {
				dp[i + 1][j + 1] += dp[i][j];
				dp[i + 1][j + 1] %= mod;
			}
		}
		if (s[i] == ')' || s[i] == '?') {
			rep(j, m) {
				dp[i + 1][j] += dp[i][j + 1];
				dp[i + 1][j] %= mod;
			}
		}
	}
	/*
	rep(i, n+1) {
		rep(j, m + 1) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	cout << dp[n][0] << endl;

}