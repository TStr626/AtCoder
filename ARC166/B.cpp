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

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	//a*b<=1e18
	//need "gcd"
	if (min(a, b) == 0) {
		return max(a, b);
	}
	return (a / gcd(a, b)) * b;
}


int main() {
	long long n, m, i, j, k, h, w, x, y, z, ans, cur, res, jud, mod, inf = 1000000000000000000;
	cin >> n >> x >> y >> z;
	vector<long long> p(1 << 3);
	p[0] = 1; p[1] = x; p[2] = y; p[4] = z;
	p[3] = lcm(x, y); p[5] = lcm(x, z); p[6] = lcm(y, z); p[7] = lcm(p[3], p[4]);
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	vector<vector<long long>> dp(n + 1, vector<long long>(1 << 3, inf));
	dp[0][0] = 0;
	rep(i, n) {
		rep(j, 1 << 3) {
			dp[i + 1][j] = dp[i][j];
		}
		rep(j, 1 << 3) {
			rep(k, 1 << 3) {
				dp[i + 1][j | k] = min(dp[i + 1][j | k], dp[i][j] + p[k] - (((a[i] - 1) % p[k]) + 1));
			}
		}
	}
	cout << dp[n][7] << endl;

	
}