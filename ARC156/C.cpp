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

vector<set<int>> g;
vector<int> p;
vector<bool> er;
pair<int,int> diam(vector<set<int>> g, int r) {
	// returns diameter of "connected component with r in g";
	// it may fail if g is not tree
	// "root"-"cur" in the end has diameter;
	int n = g.size(), i, cur, res, ans, root;
	queue<int> q;
	vector<int> d1(n, n), d2(n, n);
	vector<bool> checked1(n, false), checked2(n, false);

	q.push(r);
	d1[r] = 0; checked1[r] = true;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (auto res : g[cur]) {
			if (!checked1[res]) {
				checked1[res] = true;
				d1[res] = d1[cur] + 1;
				q.push(res);
			}
		}
	}
	root = cur;

	q.push(root);
	d2[root] = 0; checked2[root] = true;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (auto res : g[cur]) {
			if (!checked2[res]) {
				checked2[res] = true;
				d2[res] = d2[cur] + 1;
				q.push(res);
			}
		}
	}
	ans = d2[cur];
	return { root,cur };
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	g.resize(n);
	rep(i, n - 1) {
		cin >> x >> y;
		x--; y--;
		g[x].insert(y);
		g[y].insert(x);
	}
	
	m = n;
	p.resize(n);
	er.resize(n, false);
	pair<int, int> pa;
	while (m > 0) {
		while (i < n && er[i]) {
			i++;
		}
		pa = diam(g, 0);
		x = pa.first;
		y = pa.second;
		p[x] = y;
		p[y] = x;
		for (auto t : g[x]) {
			g[t].erase(x);
		}
		for (auto t : g[y]) {
			g[t].erase(y);
		}
		er[x] = er[y] = true;
		m -= 2;
	}
	rep(i, n) {
		if (i) cout << ' ';
		cout << p[i] + 1;
	}
}