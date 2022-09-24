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

vector<vector<long long>> g;
vector<long long> ansv;
long long x, y;
void dfs(long long cur,long long p) {
	int i, res;
	ansv.push_back(cur);

	if (cur == y) {
		rep(i, ansv.size()) {
			if (i) {
				cout << ' ';
			}
			cout << ansv[i] + 1;
		}
		cout << endl;
		exit(0);
	}
	
	
	rep(i, g[cur].size()) {
		res = g[cur][i];
		if (p == res) {
			continue;
		}
		dfs(res, cur);
	}
	ansv.pop_back();
}
int main() {
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod, inf;
	long long u, v;
	cin >> n >> x >> y;
	x--; y--;
	g.resize(n);
	rep(i, n - 1) {
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(x, -1);
	
}