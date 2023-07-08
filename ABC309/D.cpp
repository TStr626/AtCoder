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
void yes() {
	cout << "Yes" << endl;
}
void no() {
	cout << "No" << endl;
}
void vec_h(vector<long long> a) {
	int n = a.size(), i;
	rep(i, n) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
}
void vec_v(vector<long long> a) {
	for (auto c : a) {
		cout << c << endl;
	}
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long n1, n2;
	cin >> n1 >> n2 >> m;
	vector<vector<long long>> g(n1 + n2);
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	queue<long long> qu;
	vector<long long> d(n1 + n2, n1 + n2);
	d[0] = 0;
	d[n1 + n2 - 1] = 0;
	qu.push(0);
	qu.push(n1 + n2 - 1);
	while (qu.size()) {
		x = qu.front();
		qu.pop();
		for (auto v : g[x]) {
			if (d[v] > d[x] + 1) {
				qu.push(v);
				d[v] = d[x] + 1;
			}
		}
	}
	cur = 0; res = 0;
	rep(i, n1) {
		cur = max(cur, d[i]);
	}
	rep(i, n2) {
		res = max(res, d[n1 + i]);
	}
	ans = cur + res + 1;
	cout << ans << endl;
}