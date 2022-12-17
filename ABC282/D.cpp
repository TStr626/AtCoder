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

bool isBipartite(vector<vector<int>> g, vector<int>&col, bool distinctComponent) {
	// it returns col[] for colorling as [0,1] mod 2, if g is Bipartite
	// distinctComponent true:diff component has diff number, false:all [0,1]
	int n = g.size(), i, j, cur, res, cnt;
	queue<int> qu;
	col.assign(n, -1);
	cnt = 0;
	for (i = 0; i < n; i++) {
		if (col[i] != -1) {
			continue;
		}

		col[i] = cnt;
		qu.push(i);
		while (qu.size()) {
			cur = qu.front();
			qu.pop();
			for (auto res : g[cur]) {
				if (col[res] == -1) {
					col[res] = 1 ^ col[cur];
					qu.push(res);
					continue;
				}
				if (col[res] == col[cur]) {
					// failed to color
					return false;
				}
			}
		}

		if (distinctComponent) {
			cnt += 2;
		}
	}
	return true;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(0));
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vector<int> col(n, -1);
	if (isBipartite(g, col, true) == false) {
		cout << 0 << endl;
		return 0;
	}

	ans = n * (n - 1) / 2 - m;
	map<int, int> mp;
	rep(i, n) {
		ans -= mp[col[i]];
		mp[col[i]]++;
	}
	cout << ans << endl;
}