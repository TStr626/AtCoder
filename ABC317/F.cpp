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

#define vi vector<long long>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvvvvvi vector<vvvvvi>
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<long long> a(3);
	rep(i, 3) {
		cin >> a[i];
	}

	vvvvvvi dp(62, vvvvvi(a[0], vvvvi(a[1], vvvi(a[2], vvi(8, vi(8))))));
	// flag k1=already smaller than n, k2=already greater than 0
	long long b, j1, j2, j3, k1, k2;
	dp[61][0][0][0][0][0] = 1;
	for (i = 60; i >= 0; i--) {
		b = (1ll << i);
		rep(j1, a[0]) {
			rep(j2, a[1]) {
				rep(j3, a[2]) {

					// (x1,x2)=(0,0)
					if ((n & b) == 0) {
						// off bit
						rep(k1, 8) {
							rep(k2, 8) {
								dp[i][j1][j2][j3][k1][k2] += dp[i + 1][j1][j2][j3][k1][k2];
								dp[i][j1][j2][j3][k1][k2] %= mod;
							}
						}
					}
					else {
						// on bit
						rep(k1, 8) {
							rep(k2, 8) {
								dp[i][j1][j2][j3][k1 | 7][k2] += dp[i + 1][j1][j2][j3][k1][k2];
								dp[i][j1][j2][j3][k1 | 7][k2] %= mod;
							}
						}
					}

					// (x1,x2)=(1,0)
					if ((n & b) == 0) {
						// off bit
						rep(k1, 8) {
							if ((k1 & 1) == 0 || (k1 & 4) == 0) {
								continue;
							}
							rep(k2, 8) {
								dp[i][(j1 + b) % a[0]][j2][(j3 + b) % a[2]][k1][k2 | 5] += dp[i + 1][j1][j2][j3][k1][k2];
								dp[i][(j1 + b) % a[0]][j2][(j3 + b) % a[2]][k1][k2 | 5] %= mod;
							}
						}
					}
					else {
						// on bit
						rep(k1, 8) {
							rep(k2, 8) {
								dp[i][(j1 + b) % a[0]][j2][(j3 + b) % a[2]][k1 | 2][k2 | 5] += dp[i + 1][j1][j2][j3][k1][k2];
								dp[i][(j1 + b) % a[0]][j2][(j3 + b) % a[2]][k1 | 2][k2 | 5] %= mod;
							}
						}
					}

					// (x1,x2)=(0,1)
					if ((n & b) == 0) {
						// off bit
						rep(k1, 8) {
							if ((k1 & 2) == 0 || (k1 & 4) == 0) {
								continue;
							}
							rep(k2, 8) {
								dp[i][j1][(j2 + b) % a[1]][(j3 + b) % a[2]][k1][k2 | 6] += dp[i + 1][j1][j2][j3][k1][k2];
								dp[i][j1][(j2 + b) % a[1]][(j3 + b) % a[2]][k1][k2 | 6] %= mod;
							}
						}
					}
					else {
						// on bit
						rep(k1, 8) {
							rep(k2, 8) {
								dp[i][j1][(j2 + b) % a[1]][(j3 + b) % a[2]][k1 | 1][k2 | 6] += dp[i + 1][j1][j2][j3][k1][k2];
								dp[i][j1][(j2 + b) % a[1]][(j3 + b) % a[2]][k1 | 1][k2 | 6] %= mod;
							}
						}
					}

					// (x1,x2)=(1,1)
					if ((n & b) == 0) {
						// off bit
						rep(k1, 8) {
							if ((k1 & 1) == 0 || (k1 & 2) == 0) {
								continue;
							}
							rep(k2, 8) {
								dp[i][(j1 + b) % a[0]][(j2 + b) % a[1]][j3][k1][k2 | 3] += dp[i + 1][j1][j2][j3][k1][k2];
								dp[i][(j1 + b) % a[0]][(j2 + b) % a[1]][j3][k1][k2 | 3] %= mod;
							}
						}
					}
					else {
						// on bit
						rep(k1, 8) {
							rep(k2, 8) {
								dp[i][(j1 + b) % a[0]][(j2 + b) % a[1]][j3][k1 | 4][k2 | 3] += dp[i + 1][j1][j2][j3][k1][k2];
								dp[i][(j1 + b) % a[0]][(j2 + b) % a[1]][j3][k1 | 4][k2 | 3] %= mod;
							}
						}
					}
				}
			}
		}
	}
	ans = 0;
	rep(k1, 8) {
		ans += dp[0][0][0][0][k1][7];
		ans %= mod;
	}
	cout << ans << endl;
}