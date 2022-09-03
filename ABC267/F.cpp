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

vector<int> d1, p1, p2;
pair<int,int> diam(vector<vector<int>> g) {
	// returns diameter of tree;
	// g must be tree graph;
	// "root"-"cur" in the end has diameter;
	int n = g.size(), i, cur, res, ans, root;
	queue<int> q;
	//vector<int> d1(n, n), d2(n, n);
	vector<bool> checked1(n, false), checked2(n, false), checked3(n, false);

	q.push(0);
	d1[0] = 0; checked1[0] = true;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (i = 0; i < g[cur].size(); i++) {
			res = g[cur][i];
			if (!checked1[res]) {
				checked1[res] = true;
				d1[res] = d1[cur] + 1;
				q.push(res);
			}
		}
	}
	root = cur;

	q.push(root);
	p1[root] = -1; checked2[root] = true;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (i = 0; i < g[cur].size(); i++) {
			res = g[cur][i];
			if (!checked2[res]) {
				checked2[res] = true;
				p1[res] = cur;
				q.push(res);
			}
		}
	}
	ans = cur;

	q.push(cur);
	p2[cur] = -1; checked3[cur] = true;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (i = 0; i < g[cur].size(); i++) {
			res = g[cur][i];
			if (!checked3[res]) {
				checked3[res] = true;
				p2[res] = cur;
				q.push(res);
			}
		}
	}
	return { root,ans };
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf;
	cin >> n;
	m = n - 1;
	d1.resize(n,n);
	p1.resize(n,-1);
	p2.resize(n,-1);
	vector<vector<int>> g(n, vector<int>(0));
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	pair<int, int> di = diam(g);
	/*
	cout << di.first+1 << ' ' << di.second+1 << endl;
	rep(i, n) {
		cout << p1[i] << ' ';
	}
	cout << endl;
	rep(i, n) {
		cout << p2[i] << ' ';
	}
	cout << endl;
	*/
	
	vector<vector<int>> dbl1(n, vector<int>(21, -1)), dbl2(n, vector<int>(21, -1));
	rep(i, n) {
		dbl1[i][0] = p1[i];
		dbl2[i][0] = p2[i];
	}

	rep(j, 20) {
		rep(i, n) {
			if (dbl1[i][j] != -1) {
				dbl1[i][j + 1] = dbl1[dbl1[i][j]][j];
			}
			else {
				dbl1[i][j + 1] = -1;
			}
			if (dbl2[i][j] != -1) {
				dbl2[i][j + 1] = dbl2[dbl2[i][j]][j];
			}
			else {
				dbl2[i][j + 1] = -1;
			}
		}
	}

	
	long long query;
	cin >> query;
	while (query--) {
		cin >> x >> k;
		x--;
		ans = -1;

		cur = k; res = x; j = 0;
		while (cur > 0) {
			if (cur % 2 && res != -1) {
				res = dbl1[res][j];
			}
			cur /= 2;
			j++;
		}

		if (res != -1) {
			ans = res;
		}

		cur = k; res = x; j = 0;
		while (cur > 0) {
			if (cur % 2 && res != -1) {
				res = dbl2[res][j];
			}
			cur /= 2;
			j++;
		}

		if (res != -1) {
			ans = res;
		}


		if (ans != -1) {
			ans++;
		}
		cout << ans << endl;
	}
	
}