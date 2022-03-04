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
#include <atcoder/maxflow>
using namespace std;
using namespace atcoder;

# define rep(i,n) for(i=0; i<n; i++)

vector<vector<int>> bat(50, vector<int>(50, 0));
vector<int> cnt, win;
int n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;

bool solve(int res) {
	vector<int> curcnt = cnt, curwin = win;
	mf_graph<int> g(n * (n + 1) + 2);
	int s = n * (n + 1), t = n * (n + 1) + 1, inf = 10000000;
	for (j = 0; j < n; j++) {
		if (bat[res][j] == 1) {
			curwin[res]++;
			curcnt[j]--;
		}
	}

	rep(i, n) {
		if (i != res && curwin[res] <= curwin[i]) {
			return false;
		}
	}

	cur = 0;
	rep(i, n) {
		for (j = i + 1; j < n; j++) {
			if (i == res || j == res) continue;
			if (bat[i][j] == 1) {
				cur++;
				g.add_edge(s, i * n + j, 1);
				g.add_edge(i * n + j, n * n + i, inf);
				g.add_edge(i * n + j, n * n + j, inf);
			}
		}
	}

	rep(i, n) {
		if (i == res) continue;
		g.add_edge(n * n + i, t, curwin[res] - curwin[i] - 1);
	}
	jud = g.flow(s, t);
	//cout << jud << endl;
	if (jud == cur) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	cin >> n >> m;

	cnt.resize(n, n - 1);
	win.resize(n, 0);

	rep(i, n) {
		for (j = i + 1; j < n; j++) {
			bat[i][j] = 1;
			bat[j][i] = 1;
		}
	}
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		cnt[x]--; cnt[y]--; win[x]++;
		bat[x][y] = 0;
		bat[y][x] = 0;
	}

	vector<int> ansp;
	rep(res, n) {
		if (solve(res)) {
			ansp.push_back(res);
		}
	}
	rep(i, ansp.size()) {
		if (i > 0) cout << ' ';
		cout << ansp[i] + 1;
	}
	cout << endl;


}