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
	long long from;
	long long to;
	long long cost;
};
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 1000000000000000;
	long long u, v, c;
	cin >> n >> m >> k;
	vector<vector<edge>> g(n, vector<edge>(0));
	vector<edge> ev(m);
	edge e;
	rep(i, m) {
		cin >> ev[i].from >> ev[i].to >> ev[i].cost;
		ev[i].from--; ev[i].to--;
	}
	vector<long long> d(n, inf);
	d[0] = 0;
	rep(i, k) {
		cin >> x;
		x--;
		u = ev[x].from;
		v = ev[x].to;
		c = ev[x].cost;
		d[v] = min(d[v], d[u] + c);
	}
	if (d[n - 1] == inf) {
		cout << -1 << endl;
	}
	else {
		cout << d[n - 1] << endl;
	}
}