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
	long long cost;
};
long long warshall_floyd(vector<vector<edge>> g) {
	// if there is a negative cycle, some of d[i][i]<0
	long long n = g.size(), i, j, k, ans, inf = 2000000000000000000;
	vector<vector<long long>> d(n, vector<long long>(n, inf));
	vector<vector<bool>> edgeon(n, vector<bool>(n, false)), edgecount(n, vector<bool>(n, false));

	for (i = 0; i < n; i++) {
		d[i][i] = 0;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < g[i].size(); j++) {
			d[i][g[i][j].to] = g[i][j].cost;
			edgeon[i][g[i][j].to] = true;
		}
	}

	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i == j || i == k || j == k) continue;
				if (d[i][k] < inf && d[k][j] < inf) {
					if(edgeon[i][j] && (d[i][k]+d[k][j])<=d[i][j]){
						edgecount[i][j] = true;
					}
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		/*
		rep(i, n) {
			rep(j, n) {
				cout << edgecount[i][j];
			}
			cout << endl;
		}
		cout << endl;
		*/

	}

	ans = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) continue;
			if (edgecount[i][j]){
				ans++;
			}
		}
	}

	return ans / 2;
}
	
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long u, v, c;
	cin >> n >> m;
	edge e;
	vector<vector<edge>> g(n, vector<edge>(0));
	
	rep(i, m) {
		cin >> u >> v >> c;
		u--; v--;
		e.to = v; e.cost = c;
		g[u].push_back(e);
		e.to = u;
		g[v].push_back(e);
	}
	cout << warshall_floyd(g) << endl;
}