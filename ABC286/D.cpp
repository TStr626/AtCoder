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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> x;
	vector<long long> a(n), b(n);
	rep(i, n) {
		cin >> a[i] >> b[i];
	}
	vector<bool> dp(x + 1, false);
	dp[0] = true;
	rep(i, n) {
		rep(j, b[i]) {
			for (k = x - a[i]; k >= 0; k--) {
				dp[k + a[i]] = dp[k] || dp[k + a[i]];
			}
		}
	}
	if (dp[x] == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}