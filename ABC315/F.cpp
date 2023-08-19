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

struct pos {
	long long x;
	long long y;
};
double euc(pos a, pos b) {
	long long dx = abs(a.x - b.x), dy = abs(a.y - b.y);
	return sqrt(dx * dx + dy * dy);
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<pos> vp(n);
	rep(i, n) {
		cin >> vp[i].x >> vp[i].y;
	}
	// max count of possible penalty
	k = 40;

	vector<vector<double>> dp(n, vector<double>(k, 100000000000000));
	dp[0][0] = 0;
	rep(i, n - 1) {
		rep(j, k) {
			rep(x, k) {
				// out of bounds
				if (j + x >= k || i + x + 1 >= n) {
					continue;
				}

				dp[i + 1 + x][j + x] = min(dp[i + 1 + x][j + x], dp[i][j] + euc(vp[i], vp[i + 1 + x]));
			}
		}
	}
	double dans = dp[n - 1][0];
	cur = 1;
	for (x = 1; x < k; x++) {
		dans = min(dans, dp[n - 1][x] + cur);
		cur *= 2;
	}
	cout << setprecision(9);
	cout << dans << endl;
}