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

vector<vector<int>>  g;

void input_graph(int n, int m, bool directed, bool oneindexed) {
	// "directed" var. "T" - directed, "F" - undirected;
	// "oneindexed" var. "T" - 1-indexed, "F"- 0-indexed;
	int i, u, v;
	g.resize(n);
	for (i = 0; i < m; i++) {
		cin >> u >> v;
		if (oneindexed) {
			u--; v--;
		}
		g[u].push_back(v);
		if (!directed) g[v].push_back(u);
	}
	return;
}

vector<bool> checked;
vector<int> u1, v1, u2, v2;
void dfs(int cur) {
	int j, res;
	checked[cur] = true;
	
	rep(j, g[cur].size()) {
		res = g[cur][j];
		if (checked[res] == false) {
			u1.push_back(cur);
			v1.push_back(res);
			dfs(res);
		}
	}
	return;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	
	input_graph(n, m, 0, 1);

	// T1 by DFS
	checked.resize(n, false);
	
	dfs(0);
	
	rep(i, n - 1) {
		cout << u1[i] + 1 << ' ' << v1[i] + 1 << endl;
	}
	

	// T2 by BFS
	rep(i, n) {
		checked[i] = false;
	}
	queue<int> qu;
	qu.push(0); checked[0] = true;
	while (!qu.empty()) {
		cur = qu.front();
		qu.pop();
		rep(j, g[cur].size()) {
			res = g[cur][j];
			if (checked[res] == false) {
				u2.push_back(cur);
				v2.push_back(res);
				checked[res] = true;
				qu.push(res);
			}
		}
	}
	
	rep(i, n - 1) {
		cout << u2[i] + 1 << ' ' << v2[i] + 1 << endl;
	}
	

}
