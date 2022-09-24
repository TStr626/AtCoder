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

struct dsu {
	// disjoint set : union find
	vector<int> p;

	dsu() {}
	dsu(int n) : p(n) {
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
	}

	int root(int a) {
		if (p[a] == a) {
			return a;
		}
		else {
			return p[a] = root(p[a]);
		}
	}

	void unite(int a, int b) {
		int x = root(a), y = root(b);
		if (x == y) {
			return;
		}
		else {
			p[x] = y; return;
		}
	}

	bool same(int a, int b) {
		return root(a) == root(b);
	}

};

struct uedge {
	// undirected edge
	long long u;
	long long v;
	long long cost;

};

bool costsort(const uedge& e, const uedge& f) {
	return e.cost < f.cost;
}

struct Kruskal {
	// Minimum spanning tree
	// need "struct dsu"
	// vector<uedge> original(base graph) to vector<uedge> result(MST);
	// 0-indexed
	dsu d;
	long long wsum;
	vector<uedge> original, result;
	long long n;
	Kruskal(vector<uedge>& e, long long n_) : original(e), n(n_) {
		init();
	}
	void init() {
		sort(original.begin(), original.end(), costsort);
		d = dsu(n);
		wsum = 0;
		for (int i = 0; i < original.size(); i++) {
			uedge e = original[i];
			if (!d.same(e.u, e.v)) {
				d.unite(e.u, e.v);
				wsum += e.cost;
				result.push_back(e);
			}
		}
	}
};

int main() {
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod = 998244353, inf;
	cin >> n >> m;
	vector<long long> x(n), y(n);
	rep(i, n) {
		cin >> x[i];
	}
	rep(i, n) {
		cin >> y[i];
	}

	dsu d(n);
	vector<vector<uedge>> g(4,vector<uedge>(0));
	long long u, v;
	uedge e;
	// road
	rep(i, m) {
		cin >> u >> v;
		u--; v--;
		e.u = u; e.v = v;
		cin >> e.cost;

		d.unite(u, v);
		rep(j, 4) {
			g[j].push_back(e);
		}
		
	}

	// airport
	e.v = n;
	rep(i, n) {
		e.u = i;
		e.cost = x[i];
		g[1].push_back(e);
	}
	
	// port
	e.v = n;
	rep(i, n) {
		e.u = i;
		e.cost = y[i];
		g[2].push_back(e);
		g[3].push_back(e);
	}

	// both
	e.v = n + 1;
	rep(i, n) {
		e.u = i;
		e.cost = x[i];
		g[3].push_back(e);
	}

	jud = 1;
	rep(i, n) {
		if (!d.same(i, 0)) {
			jud = 0;
		}
	}
	Kruskal k0 = Kruskal(g[0], n);
	Kruskal k1 = Kruskal(g[1], n + 1);
	Kruskal k2 = Kruskal(g[2], n + 1);
	Kruskal k3 = Kruskal(g[3], n + 2);

	ans = min(k1.wsum, min(k2.wsum, k3.wsum));
	if (jud) {
		ans = min(ans, k0.wsum);
	}
	cout << ans << endl;
}