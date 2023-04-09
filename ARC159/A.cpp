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

vector<vector<long long>> warshall_floyd(vector<vector<long long>> g) {
	// if there is a negative cycle, some of d[i][i]<0
	long long n = g.size(), i, j, k, inf = 2000000000000000000;
	vector<vector<long long>> d(n, vector<long long>(n, inf));

	/*
	for (i = 0; i < n; i++) {
		d[i][i] = 0;
	}
	*/
	for (i = 0; i < n; i++) {
		for (j = 0; j < g[i].size(); j++) {
			d[i][g[i][j]] = 1;
		}
	}

	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (d[i][k] < inf && d[k][j] < inf) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (d[i][j] == inf) {
				d[i][j] = -1;
			}
		}
	}
	return d;
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> k;
	vector<vector<long long>> a(n, vector<long long>(n));
	vector<vector<long long>> g(n);
	rep(i, n) {
		rep(j, n) {
			cin >> a[i][j];
			if (a[i][j]) {
				g[i].push_back(j);
			}
		}
	}

	auto d = warshall_floyd(g);
	long long query;
	cin >> query;
	while (query--) {
		cin >> x >> y;
		x--; y--;
		cout << d[x % n][y % n] << endl;
	}
}