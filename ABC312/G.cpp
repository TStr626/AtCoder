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

vector<vector<long long>> g;
long long n, ans, cur;
vector<long long> d, dp;
long long dfs1(long long x, long long p, long long c) {
	cur += c;
	for (auto y : g[x]) {
		if (y == p) {
			continue;
		}
		d[y] = c + 1;
		dp[x] += dfs1(y, x, c + 1);
	}
	return dp[x];
}
void dfs2(long long x, long long p, long long c) {
	ans += c;
	for (auto y : g[x]) {
		if (y == p) {
			continue;
		}
		dfs2(y, x, c + n - 2 *dp[y]);
	}
	return;
}

int main() {
	long long m, i, j, k, h, w, x, y, res, jud, mod;
	cin >> n;
	g.resize(n);
	rep(i, n - 1) {
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dp.resize(n, 1);
	d.resize(n, n);
	d[0] = 0;
	cur = 0;
	dfs1(0, -1, 0);
	cur -= n - 1;
	ans = 0;
	dfs2(0, -1, cur);
	ans = (n * (n - 1) * (n - 2)) / 6 - (ans / 2);
	cout << ans << endl;
}