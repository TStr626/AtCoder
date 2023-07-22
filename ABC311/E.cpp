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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> h >> w >> n;
	vector<vector<bool>> wall(h + 1, vector<bool>(w + 1, false));
	rep(i, n) {
		cin >> x >> y;
		// x--; y--;
		wall[x][y] = true;
	}
	vector<vector<long long>> dp(h + 1, vector<long long>(w + 1, 0));
	ans = 0;
	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++) {
			if (wall[i][j] == true) {
				continue;
			}
			cur = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
			dp[i][j] = cur + 1;
			ans += dp[i][j];
		}
	}
	cout << ans << endl;
}