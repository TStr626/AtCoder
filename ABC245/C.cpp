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

int main() {
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod;
	cin >> n >> k;
	vector<long long> a(n), b(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}
	vector<vector<bool>> dp(n, vector<bool>(2, false));
	dp[0][0] = true;
	dp[0][1] = true;
	rep(i, n - 1) {
		if ((abs(a[i] - a[i + 1]) <= k) && dp[i][0]) {
			dp[i + 1][0] = true;
		}
		if ((abs(a[i] - b[i + 1]) <= k) && dp[i][0]) {
			dp[i + 1][1] = true;
		}

		if ((abs(b[i] - a[i + 1]) <= k) && dp[i][1]) {
			dp[i + 1][0] = true;
		}
		if ((abs(b[i] - b[i + 1]) <= k) && dp[i][1]) {
			dp[i + 1][1] = true;
		}
	}
	/*
	rep(i, n) {
		cout << dp[i][0];
	}
	cout << endl;
	rep(i, n) {
		cout << dp[i][1];
	}
	*/
	if (dp[n - 1][0] || dp[n - 1][1]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}