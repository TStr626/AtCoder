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
	long long z;
	cin >> x >> y >> z;
	string s;
	cin >> s;
	n = s.size();
	vector<vector<long long>> dp(n + 1, vector<long long>(2, 10000000000000000));
	dp[0][0] = 0; dp[0][1] = z;
	for (i = 1; i <= n; i++) {
		if (s[i - 1] == 'a') {
			dp[i][0] = min(dp[i][0], dp[i - 1][0] + x);
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + y);
		}
		else {
			dp[i][0] = min(dp[i][0], dp[i - 1][0] + y);
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + x);
		}

		dp[i][0] = min(dp[i][0], dp[i][1] + z);
		dp[i][1] = min(dp[i][1], dp[i][0] + z);
	}
	ans = min(dp[n][0], dp[n][1]);
	cout << ans << endl;
}