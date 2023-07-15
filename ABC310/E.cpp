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
	cin >> n;
	string s;
	cin >> s;
	vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
	ans = 0;
	
	rep(i, n) {
		if (s[i] == '0') {
			dp[i + 1][0] = 1;
			dp[i + 1][1] = dp[i][0] + dp[i][1];
		}
		else {
			dp[i + 1][0] = dp[i][1];
			dp[i + 1][1] = dp[i][0] + 1;
		}
		ans += dp[i + 1][1];
	}
	cout << ans << endl;
}