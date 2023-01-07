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

long long p;
set<int> cpath;
vector<vector<long long>> g;
void dfs(int u) {
	if (p >= 1000000) {
		return;
	}
	cpath.insert(u);
	p++;
	for (auto v : g[u]) {
		if (cpath.count(v)) {
			continue;
		}
		dfs(v);
	}
	cpath.erase(u);
}
int main() {
	long long n, m, i, j, k, h, w, x, y, z, ans, cur, res, jud, mod, inf = 1000000;
	long long u, v;
	cin >> n >> m;
	g.resize(n);
	rep(i, m) {
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	p = 0;
	dfs(0);
	cout << p << endl;
}