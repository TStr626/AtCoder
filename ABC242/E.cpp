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

void solve() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	string s;
	cin >> n;
	cin >> s;
	// digit dp
	char c;
	vector<vector<long long>> dp((n+1) / 2 + 1, vector<long long>(26, 0));
	// X < S
	rep(i, (n+1) / 2) {
		cur = 0;
		rep(j, 26) {
			cur += dp[i][j];
			cur %= mod;
		}
		rep(j, 26) {
			c = 'A' + j;
			dp[i + 1][j] = cur;
			if (c < s[i]) {
				dp[i + 1][j] += 1;
			}
			dp[i + 1][j] %= mod;
		}

		/*
		rep(j, 26) {
			cout << dp[i + 1][j] << ' ';
		}
		cout << endl;
		*/
	}
	// X == S
	string t = "";
	rep(i, n / 2) {
		t.push_back(s[i]);
	}
	reverse(t.begin(), t.end());
	jud = 1;
	rep(i, n / 2) {
		if (t[i] < s[i + (n + 1) / 2]) {
			break;
		}
		else if (t[i] > s[i + (n + 1) / 2]) {
			jud = 0;
			break;
		}
	}
	if (jud) {
		ans = 1;
	}
	else {
		ans = 0;
	}

	rep(j, 26) {
		ans += dp[(n+1) / 2][j];
		ans %= mod;
	}
	cout << ans << endl;
	return;
}
int main() {
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
}