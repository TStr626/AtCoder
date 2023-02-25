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

#define vl vector<long long>
#define vvl vector<vl>
#define vvvl vector<vvl>

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) {
		cin >> s[i];
	}

	vvvl dp(h, vvl(w, vl(3, 0)));
	dp[0][0][0] = 1;
	rep(i, h) {
		rep(j, w) {
			rep(x, 3) {
				// across
				if (j < w - 1) {
					dp[i][j + 1][x] += dp[i][j][x];
					dp[i][j + 1][x] %= mod;
					if (x < 2 && s[i][j] == 'Y' && s[i][j + 1] == 'Y') {
						dp[i][j + 1][x + 1] += dp[i][j][x];
						dp[i][j + 1][x + 1] %= mod;
					}
				}
				// down
				if (i < h - 1) {
					dp[i + 1][j][x] += dp[i][j][x];
					dp[i + 1][j][x] %= mod;
					if (x < 2 && s[i][j] == 'Y' && s[i + 1][j] == 'Y') {
						dp[i + 1][j][x + 1] += dp[i][j][x];
						dp[i + 1][j][x + 1] %= mod;
					}
				}
			}
		}
	}
	/*
	ans = 0;
	rep(i, h) {
		rep(j, w) {
			rep(x, 3) {
				cout << dp[i][j][x];
			}
			cout << endl;
			ans += dp[i][j][1];
			ans += dp[i][j][2] * 2;
			ans %= mod;
		}
	}
	*/
	ans = dp[h - 1][w - 1][1] + dp[h - 1][w - 1][2] * 2;
	ans %= mod;
	cout << ans << endl;

}