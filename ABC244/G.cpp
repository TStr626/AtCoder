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

vector<vector<int>> input_graph(int n, int m, bool directed, bool oneindexed) {
	// "directed" var. "T" - directed, "F" - undirected;
	// "oneindexed" var. "T" - 1-indexed, "F"- 0-indexed;
	int i, u, v;
	dsu d(n);
	vector<vector<int>>  g(n, vector<int>(0));
	for (i = 0; i < m; i++) {
		cin >> u >> v;
		if (oneindexed) {
			u--; v--;
		}
		if (!d.same(u, v)) {
			d.unite(u, v);
			g[u].push_back(v);
			if (!directed) g[v].push_back(u);
		}
	}
	return g;
}
vector<vector<int>> g;
vector<int> ansp(0);
vector<int> cnt;
string s;
void dfs(int cur, int p) {
	int i, res;
	ansp.push_back(cur);
	cnt[cur] = (cnt[cur] + 1) % 2;
	rep(i, g[cur].size()) {
		if (g[cur][i] == p) continue;
		dfs(g[cur][i], cur);
	}
	if (cur!=0 && ((s[cur]-'0') != cnt[cur])) {
		ansp.push_back(p);
		cnt[p] = (cnt[p] + 1) % 2;
		ansp.push_back(cur);
		cnt[cur] = (cnt[cur] + 1) % 2;
	}
	if (cur != 0) {
		ansp.push_back(p);
		cnt[p] = (cnt[p] + 1) % 2;
	}
	return;
}
int main() {
	int n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf = 1000000000;
	cin >> n >> m;
	g = input_graph(n, m, 0, 1);
	/*
	rep(i, n) {
		rep(j, g[i].size()) {
			cout << g[i][j]+1;
		}
		cout << endl;
	}
	*/
	cnt.resize(n, 0);
	cin >> s;
	dfs(0, -1);
	if ((s[0] - '0') != cnt[0]) {
		ansp.push_back(g[0][0]);
		ansp.push_back(0);
		ansp.push_back(g[0][0]);
	}

	cout << ansp.size() << endl;

	rep(i, ansp.size()) {
		if (i) cout << ' ';
		cout << ansp[i]+1;
	}
	cout << endl;
}