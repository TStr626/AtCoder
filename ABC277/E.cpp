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

struct edge {
	long long to;
	long long cost;
};
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 100000000;
	cin >> n >> m >> k;
	vector<vector<edge>> g(2 * n);
	edge e;
	long long c;

	e.cost = 1;
	rep(i, m) {
		cin >> x >> y >> c;
		x--; y--;
		if (c == 0) {
			x += n; y += n;
		}
		e.to = y;
		g[x].push_back(e);
		e.to = x;
		g[y].push_back(e);
	}

	e.cost = 0;
	rep(i, k) {
		cin >> c;
		c--;
		e.to = c + n;
		g[c].push_back(e);
		e.to = c;
		g[c + n].push_back(e);
	}

	vector<long long> d(2 * n, inf);
	deque<long long> dq;
	d[0] = 0; dq.push_back(0);
	while (dq.size()) {
		cur = dq.front();
		dq.pop_front();
		rep(j, g[cur].size()) {
			res = g[cur][j].to;
			c = g[cur][j].cost;
			if (d[res] > d[cur] + c) {
				d[res] = d[cur] + c;
				if (c == 0) {
					dq.push_front(res);
				}
				else {
					dq.push_back(res);
				}
			}
		}
	}
	ans = min(d[n - 1], d[2 * n - 1]);
	if (ans == inf) {
		ans = -1;
	}
	cout << ans << endl;

}