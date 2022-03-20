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
# define vl vector<long  long>
# define vvl vector<vl>
# define vvvl vector<vvl>


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long s, t, j1, j2, j3;
	cin >> n >> m >> k >> s >> t >> x;
	s--; t--; x--;
	vector<long long> u(m), v(m);
	rep(i, m) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
	}
	vvvl dp(k + 1, vvl(n, vl(2, 0)));
	dp[0][s][0] = 1;
	rep(j1, k) {
		rep(j2, m) {
			rep(j3, 2) {
				dp[j1 + 1][v[j2]][(j3 + (v[j2] == x)) % 2] += dp[j1][u[j2]][j3];
				dp[j1 + 1][v[j2]][(j3 + (v[j2] == x)) % 2] %= mod;

				dp[j1 + 1][u[j2]][(j3 + (u[j2] == x)) % 2] += dp[j1][v[j2]][j3];
				dp[j1 + 1][u[j2]][(j3 + (u[j2] == x)) % 2] %= mod;
			}
		}
	}
	cout << dp[k][t][0] % mod << endl;
}