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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod=998244353,inf=1000000000;
	long long b;
	string s;
	cin >> n >> m;
	vector<long long> u(m), v(m);
	rep(i, m) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
	}
	vector<vector<long long>> dp((1ll << n), vector<long long>(n, inf));
	rep(i, n) {
		dp[(1ll << i)][i] = 1;
		dp[0][i] = 0;
	}

	jud = 1;
	while (jud) {
		jud = 0;
		rep(b, (1ll << n)) {
			rep(i, m) {
				if (dp[b][u[i]] + 1 < dp[b ^ (1ll << v[i])][v[i]]) {
					jud = 1;
					dp[b ^ (1ll << v[i])][v[i]] = dp[b][u[i]] + 1;
				}
				if (dp[b][v[i]] + 1 < dp[b ^ (1ll << u[i])][u[i]]) {
					jud = 1;
					dp[b ^ (1ll << u[i])][u[i]] = dp[b][v[i]] + 1;
				}
			}
		}
	}
	ans = 0;
	rep(b, (1ll<<n)) {
		cur = inf;
		rep(i, n) {
			cur = min(cur, dp[b][i]);
		}
		ans += cur;
	}
	cout << ans << endl;
}