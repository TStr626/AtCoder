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

struct scc {
	// sccv has the scc of directed-graph g
	// if g is undirected, sccv has the components
	int siz;
	vector<int> curnode;
	vector<bool> checked;
	vector<vector<int>> sccv;
	vector<int> comp;
	int c;

	void dfs1(vector<vector<int>>& g, int i) {
		checked[i] = true;
		for (int v : g[i]) {
			if (checked[v] == true) {
				continue;
			}
			dfs1(g, v);
		}
		curnode.push_back(i);
		return;
	}

	void dfs2(vector<vector<int>>& g, int i) {
		int v;
		checked[i] = false;
		sccv[c].push_back(i);
		comp[i] = c;
		for (int v : g[i]) {
			if (checked[v] == false) {
				continue;
			}
			dfs2(g, v);
		}
	}

	bool same(int u, int v) {
		return comp[u] == comp[v];
	}

	scc(vector<vector<int>>& g) {
		int i, u, v;
		siz = g.size();
		vector<vector<int>> ginv(siz, vector<int>(0));
		for (u = 0; u < siz; u++) {
			for (int v : g[u]) {
				ginv[v].push_back(u);
			}
		}

		checked.assign(siz, false);
		for (i = 0; i < siz; i++) {
			if (checked[i] == true) {
				continue;
			}
			dfs1(g, i);
		}

		comp.assign(siz, -1);
		c = 0;
		for (i = siz - 1; i >= 0; i--) {
			v = curnode[i];
			if (checked[v] == false) {
				continue;
			}
			sccv.push_back({});
			dfs2(ginv, v);
			c++;
		}
	}
};

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> m;
	vector<vector<int>> g(n);
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
	}
	
	ans = 0;
	vector<vector<bool>> checked(n, vector<bool>(n, false));
	queue<long long> qu;
	rep(i, n) {
		qu.push(i);
		checked[i][i] = true;
		while (qu.size()) {
			cur = qu.front();
			qu.pop();
			for (auto v : g[cur]) {
				if (checked[i][v]) {
					continue;
				}
				ans++;
				checked[i][v] = true;
				qu.push(v);
			}
		}
	}
	ans -= m;
	cout << ans << endl;
}