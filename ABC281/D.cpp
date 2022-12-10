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
	long long d;
	cin >> n >> k >> d;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	long long inf = 1;
	vector<vector<long long>> dp(k + 1, vector<long long>(d, -inf));
	dp[0][0] = 0;
	rep(i, n) {
		for (x = k - 1; x >= 0; x--) {
			rep(j, d) {
				if (dp[x][j] == -inf) {
					continue;
				}
				dp[x + 1][(j + a[i]) % d] = max(dp[x + 1][(j + a[i]) % d], dp[x][j] + a[i]);
			}
		}
	}
	cout << dp[k][0] << endl;
}