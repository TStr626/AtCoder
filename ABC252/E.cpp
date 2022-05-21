#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)

struct edge {
	long long to;
	long long num;
	long long cost;
};
struct comp {
	long long dist;
	long long num;
};

vector<comp> dijkstra(vector<vector<edge>> g, long long r) {
	// need "struct edge"
	// input graph g, vertexs are 0-indexed, do not include parallel edges
	// r is source
	// inf=2e18;
	long long n = g.size(), inf = 2000000000000000000, u, v, i, j;
	vector<comp> d(n, { inf,-1 });
	d[r] = { 0,-1 };
	set<pair<long long, long long>> s;
	pair<long long, long long> p;
	auto itr = s.begin();
	for (i = 0; i < n; i++) {
		p.first = d[i].dist; p.second = i;
		s.insert(p);
	}
	while (!s.empty()) {
		itr = s.begin();
		p = *itr;
		s.erase(p);
		u = p.second;
		for (j = 0; j < g[u].size(); j++) {
			v = g[u][j].to;
			if (d[u].dist + g[u][j].cost < d[v].dist) {
				s.erase({ d[v].dist,v });
				d[v].dist = d[u].dist + g[u][j].cost;
				d[v].num = g[u][j].num;
				s.insert({ d[v].dist,v });
			}
		}
	}
	return d;
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf = 1000000000000000000ll;
	long long u, v, c;
	cin >> n >> m;

	vector<vector<edge>>  g(n, vector<edge>(0));
	edge e;
	rep(i, m) {
		cin >> u >> v >> c;
		u--; v--;
		e.to = v; e.num = i; e.cost = c;
		g[u].push_back(e);
		e.to = u;
		g[v].push_back(e);
	}
	auto d = dijkstra(g, 0);
	rep(i, n - 1) {
		if (i) cout << ' ';
		cout << d[i + 1].num + 1;
	}
	cout << endl;
}
