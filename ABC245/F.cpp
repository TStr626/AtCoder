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
#include<atcoder/dsu>
#include<atcoder/scc>
using namespace std;
using namespace atcoder;

# define rep(i,n) for(i=0; i<n; i++)

int main() {
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod;
	int u, v;
	cin >> n >> m;

	vector<vector<int>> ginv(n, vector<int>(0));
	vector<bool> gpos(n, false);
	scc_graph gs(n);
	queue<int> qu;
	rep(i, m) {
		cin >> u >> v;
		u--; v--;
		ginv[v].push_back(u);
		gs.add_edge(u, v);
	}
	auto gscc = gs.scc();

	rep(i, gscc.size()) {
		if (gscc[i].size() >= 2) {
			rep(j, gscc[i].size()) {
				res = gscc[i][j];
				gpos[res] = true;
				qu.push(res);
			}
		}
	}
	while (!qu.empty()) {
		cur = qu.front();
		qu.pop();
		rep(j, ginv[cur].size()) {
			res = ginv[cur][j];
			if (!gpos[res]) {
				gpos[res] = true;
				qu.push(res);
			}
		}
	}
	ans = 0;
	rep(i, n) {
		ans += (gpos[i]);
	}
	cout << ans << endl;
}