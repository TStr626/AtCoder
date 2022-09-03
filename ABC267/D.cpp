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
	long long n, m, i, j, k, h, w, y, z, ans, cur, res, jud, mod, inf = 10000000000000ll;
	cin >> n >> m;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -inf));
	dp[0][0] = 0;
	rep(i, n) {
		rep(j, m + 1) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j < m) {
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (j + 1) * a[i]);
			}
		}
	}
	ans = dp[n][m];
	cout << ans << endl;

}