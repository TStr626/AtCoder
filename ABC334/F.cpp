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
double dist(pos a, pos b) {
	double dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> k;
	pos s;
	cin >> s.x >> s.y;
	vector<pos> vp(n);
	rep(i, n) {
		cin >> vp[i].x >> vp[i].y;
		vp[i].x -= s.x; vp[i].y -= s.y;
	}
	vector<double> ds(n), dh(n - 1), sdh(n), dpen(n);
	rep(i, n) {
		ds[i] = dist({ 0,0 }, vp[i]);
	}
	rep(i, n - 1) {
		dh[i] = dist(vp[i], vp[i + 1]);
		sdh[i + 1] = sdh[i] + dh[i];
	}
	rep(i, n - 1) {
		dpen[i] = ds[i] + ds[i + 1] - dh[i];
	}
	dpen[n - 1] = ds[n - 1];
	double dans = ds[0] + sdh[n - 1];
	vector<double> dp(n + 1);
	multiset<double> st;
	dp[0] = 0;
	st.insert(dp[0]);
	for (i = 1; i <= n; i++) {
		dp[i] = *st.begin() + dpen[i - 1];
		st.insert(dp[i]);
		if (k < st.size()) {
			st.erase(st.find(dp[i - k]));
		}
		//cout << dp[i] << endl;
	}
	dans += dp[n];
	cout << setprecision(12);
	cout << dans << endl;
}