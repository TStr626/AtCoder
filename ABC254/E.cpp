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

vector<vector<int>> input_graph(int n, int m, bool directed, bool oneindexed) {
	// "directed" var. "T" - directed, "F" - undirected;
	// "oneindexed" var. "T" - 1-indexed, "F"- 0-indexed;
	int i, u, v;
	vector<vector<int>>  g(n, vector<int>(0));
	for (i = 0; i < m; i++) {
		cin >> u >> v;
		if (oneindexed) {
			u--; v--;
		}
		g[u].push_back(v);
		if (!directed) g[v].push_back(u);
	}
	return g;
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf = 1000000000000000000ll;
	cin >> n >> m;

	auto g = input_graph(n, m, 0, 1);

	long long query, d;
	cin >> query;
	set<pair<int, int>> st;
	pair<int, int> p;
	set<int> checked;
	auto itrst = st.begin();
	auto itrch = checked.begin();
	while (query--) {
		cin >> x >> k;
		x--;
		st.insert({ 0,x });

		while (!st.empty()) {
			itrst = st.begin();
			p = *itrst;
			d = p.first;
			cur = p.second;
			checked.insert(cur);

			if (d < k) {
				rep(j, g[cur].size()) {
					res = g[cur][j];
					st.insert({ d + 1,res });
				}
			}
			st.erase(itrst);
		}

		ans = 0;
		while (!checked.empty()) {
			itrch = checked.begin();
			ans += (*itrch + 1);
			checked.erase(itrch);
		}
		cout << ans << endl;	
	}
}
