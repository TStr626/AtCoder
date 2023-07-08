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
	cin >> n >> m;
	vector<vector<long long>> g(n);
	vector<long long> d(n, 0);
	rep(i, n - 1) {
		cin >> x;
		x--;
		g[x].push_back(i + 1);
	}
	rep(i, m) {
		cin >> x >> y;
		x--; y++;
		d[x] = max(d[x], y);
	}
	ans = 0;
	rep(i, n) {
		for (auto v : g[i]) {
			d[v] = max(d[v], d[i] - 1);
		}
		if (d[i] > 0) {
			ans++;
		}
	}
	cout << ans << endl;
}