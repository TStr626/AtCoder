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
void solve() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> m;
	vector<long long> c(n);
	rep(i, n) {
		cin >> c[i];
	}
	vector<long long> u(m), v(m);
	rep(i, m) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
	}
	
	vector<vector<long long>> gg(n* n);
	rep(i, m) {
		rep(j, m) {
			if (c[u[i]] != c[u[j]]) {
				gg[v[i] * n + v[j]].push_back(u[i] * n + u[j]);
			}
			if (c[u[i]] != c[v[j]]) {
				gg[v[i] * n + u[j]].push_back(u[i] * n + v[j]);
			}
			if (c[v[i]] != c[u[j]]) {
				gg[u[i] * n + v[j]].push_back(v[i] * n + u[j]);
			}
			if (c[v[i]] != c[v[j]]) {
				gg[u[i] * n + u[j]].push_back(v[i] * n + v[j]);
			}
		}
	}
	vector<long long> d(n* n, n* n);
	queue<long long> qu;
	qu.push(n - 1);
	d[n - 1] = 0;
	while (qu.size()) {
		x = qu.front();
		qu.pop();
		for (auto y : gg[x]) {
			if (d[y] <= d[x] + 1) {
				continue;
			}
			d[y] = d[x] + 1;
			qu.push(y);
		}
	}
	if (d[(n - 1) * n] == n * n) {
		ans = -1;
	}
	else {
		ans = d[(n - 1) * n];
	}
	cout << ans << endl;
}

int main() {
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
}