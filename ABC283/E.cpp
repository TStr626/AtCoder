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

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
int main() {
	long long n, m, i, j, k, h, w, x, y, z, ans, cur, res, jud, mod, inf = 1000000;
	cin >> h >> w;
	vector<vector<int>> a(h + 2, vector<int>(w + 2));
	rep(i, h) {
		rep(j, w) {
			cin >> a[i + 1][j + 1];
		}
	}
	rep(i, h) {
		a[i + 1][0] = 2;
		a[i + 1][w + 1] = 2;
	}
	rep(j, w + 2) {
		a[0][j] = 2;
		a[h + 1][j] = 2;
	}

	vvvvi dp(h + 1, vvvi(2, vvi(2, vi(2, inf))));
	dp[0][0][0][0] = 0; dp[0][0][0][1] = 1;
	for (i = 1; i <= h; i++) {
		rep(x, 2) {
			rep(y, 2) {
				rep(z, 2) {
					dp[i][x][y][z] = min(dp[i - 1][0][x][y], dp[i - 1][1][x][y]) + z;
					// valid judge
					jud = true;
					for (j = 1; j <= w; j++) {
						if (a[i][j] == a[i][j - 1] || a[i][j] == a[i][j + 1]) {
							continue;
						}
						if ((a[i][j] ^ y) == (a[i - 1][j] ^ x) || (a[i][j] ^ y) == (a[i + 1][j] ^ z)) {
							continue;
						}
						jud = false;
						break;
					}

					if (jud == false) {
						dp[i][x][y][z] = inf;
					}
				}
			}
		}
	}

	ans = inf;
	rep(x, 2) {
		rep(y, 2) {
			rep(z, 2) {
				ans = min(ans, long long(dp[h][x][y][z]));
			}
		}
	}
	if (ans == inf) {
		ans = -1;
	}
	cout << ans << endl;
}