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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	vector<string> vs(n);
	rep(i, n) {
		cin >> vs[i];
	}
	vector<long long> du(n, n), dv(n, n);
	du[0] = 0;
	rep(i, n) {
		rep(j, m) {
			if (vs[i][j] == '1') {
				du[i + j + 1] = min(du[i + j + 1], du[i] + 1);
			}
		}
	}
	dv[n - 1] = 0;
	for (i = n - 2; i >= 0; i--) {
		rep(j, m) {
			if (vs[i][j] == '1') {
				dv[i] = min(dv[i], dv[i + j + 1] + 1);
			}
		}
	}
	/*
	rep(i, n) {
		cout << du[i] << ' ';
	}
	cout << endl;
	rep(i, n) {
		cout << dv[i] << ' ';
	}
	cout << endl;
	*/
	vector<long long> vans(n - 2, n);
	for (x = 1; x <= n - 2; x++) {
		for (i = x - m + 1; i < x; i++) {
			if (i < 0) continue;
			for (j = 0; j < m; j++) {
				y = (i + j + 1);
				if (y <= x || y >= n || vs[i][j]=='0') {
					continue;
				}
				vans[x - 1] = min(vans[x - 1], du[i] + 1 + dv[y]);
			}
			//vans[x - 1] = min(vans[x - 1], du[i] + dv[i]);
		}
	}
	rep(x, n - 2) {
		if (vans[x] == n) {
			vans[x] = -1;
		}
	}
	vec_h(vans);
}