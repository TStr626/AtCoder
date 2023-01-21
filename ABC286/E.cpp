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

struct point {
	long long cnt;
	long long val;
};
bool operator<(point a, point b) {
	if (a.cnt != b.cnt) {
		return a.cnt < b.cnt;
	}
	return a.val > b.val;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, z, ans, cur, res, jud, mod, inf = 1000000;
	cin >> n;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}
	vector<vector<point>> d(n, vector<point>(n, { n + 1,0 }));
	rep(i, n) {
		rep(j, n) {
			if (s[i][j] == 'N') {
				continue;
			}
			d[i][j].cnt = 1;
			d[i][j].val = a[j];
		}
	}
	rep(i, n) {
		d[i][i].cnt = 0;
		d[i][i].val = 0;
	}

	//warshall-floyd
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				d[i][j] = min(d[i][j], { d[i][k].cnt + d[k][j].cnt , d[i][k].val + d[k][j].val });
			}
		}
	}

	long long query;
	cin >> query;
	while (query--) {
		cin >> x >> y;
		x--; y--;
		if (d[x][y].cnt == n + 1) {
			cout << "Impossible" << endl;
		}
		else {
			cout << d[x][y].cnt << ' ' << d[x][y].val + a[x] << endl;
		}
	}
}