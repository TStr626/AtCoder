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
	long long z;
	cin >> n;
	vector<set<long long>> g(n);
	rep(i, n - 1) {
		cin >> x >> y;
		x--; y--;
		g[x].insert(y);
		g[y].insert(x);
	}
	queue<long long> qu;
	rep(i, n) {
		if (g[i].size() == 1) {
			qu.push(i);
		}
	}
	vector<long long> vans(0), vcur;
	
	while (qu.size()) {
		x = qu.front();
		qu.pop();
		if (g[x].size() == 0) {
			continue;
		}
		//cout << x << endl;

		y = *g[x].begin();
		// y is the hub of star
		vans.push_back(g[y].size());
		vcur.resize(0);
		for (auto z : g[y]) {
			vcur.push_back(z);
		}

		for (auto z : vcur) {
			for (auto x : g[z]) {
				g[x].erase(z);
				if (g[x].size() == 1) {
					qu.push(x);
				}
			}
			g[z].clear();
		}
		
	}
	sort(vans.begin(), vans.end());
	vec_h(vans);

}