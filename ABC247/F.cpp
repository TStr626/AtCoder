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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<long long> p(n), q(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	rep(i, n) {
		cin >> cur;
		q[p[i]] = cur - 1;
	}
	sort(p.begin(), p.end());
	/*
	rep(i, n) {
		cout << q[i] + 1 << ' ';
	}
	*/
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<vector<long long>> dp0(n+1, vector<long long>(2, 0)), dp1(n+1, vector<long long>(2, 0));
	dp0[1][0] = 1; dp0[1][1] = 0;
	for (i = 1; i < n; i++) {
		dp0[i + 1][0] = dp0[i][0] + dp0[i][1];
		dp0[i + 1][1] = dp0[i][0];
		dp0[i + 1][0] %= mod;
		dp0[i + 1][1] %= mod;
	}
	dp1[1][0] = 0; dp1[1][1] = 1;
	for (i = 1; i < n; i++) {
		dp1[i + 1][0] = dp1[i][0] + dp1[i][1];
		dp1[i + 1][1] = dp1[i][0];
		dp1[i + 1][0] %= mod;
		dp1[i + 1][1] %= mod;
	}

	ans = 1;
	vector<bool> check(n,true);
	rep(i, n) {
		if (check[i] == true) {
			cur = 0;
			while (check[i] == true) {
				cur++;
				check[i] = false;
				i = q[i];
			}
			res = (dp0[cur][0] + dp0[cur][1] + dp1[cur][0]) % mod;
			ans = (ans * res) % mod;
		}
	}
	cout << ans << endl;


}
