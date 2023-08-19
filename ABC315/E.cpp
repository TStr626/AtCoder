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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<vector<long long>> g(n);
	rep(i, n) {
		cin >> x;
		rep(j, x) {
			cin >> y;
			y--;
			g[i].push_back(y);
		}
	}
	set<long long> st;
	queue<long long> qu;
	qu.push(0);
	st.insert(0);
	// explore which book is needed
	while (qu.size()) {
		x = qu.front();
		qu.pop();
		rep(j, g[x].size()) {
			if (st.count(g[x][j])) {
				continue;
			}
			qu.push(g[x][j]);
			st.insert(g[x][j]);
		}
	}
	
	// reduct graph
	vector<vector<long long>> g2(n);
	vector<long long> d(n);
	rep(i, n) {
		if (!st.count(i)) {
			continue;
		}
		rep(j, g[i].size()) {
			if (!st.count(g[i][j])) {
				continue;
			}
			g2[i].push_back(g[i][j]);
			d[g[i][j]]++;
		}
	}
	// topological sort
	vector<long long> vans;
	qu.push(0);
	while (qu.size()) {
		i = qu.front();
		qu.pop();
		rep(j, g2[i].size()) {
			d[g2[i][j]]--;
			if (d[g2[i][j]] == 0) {
				vans.push_back(g2[i][j] + 1);
				qu.push(g2[i][j]);
			}
		}
	}
	reverse(vans.begin(), vans.end());
	vec_h(vans);
}