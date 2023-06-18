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
	cin >> n;
	vector<vector<long long>> dp(n + 1, vector<long long>(2, -10000000000000000));
	dp[0][0] = 0;
	rep(i, n) {
		cin >> x >> y;
		if (x == 0) {
			// safe
			dp[i + 1][0] = max(max(dp[i][0], dp[i][1]) + y, dp[i][0]);
			dp[i + 1][1] = dp[i][1];
		}
		else {
			// unsafe
			dp[i + 1][0] = dp[i][0];
			dp[i + 1][1] = max(dp[i][0] + y, dp[i][1]);
		}
	}
	ans = max(dp[n][0], dp[n][1]);
	cout << ans << endl;

}