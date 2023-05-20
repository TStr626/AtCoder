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
	long long query, t;
	cin >> n >> query;
	vector<set<long long>> g(n);
	ans = n;
	while (query--) {
		cin >> t;
		if (t == 1) {
			cin >> x >> y;
			x--; y--;
			if (g[x].empty()) {
				ans--;
			}
			if (g[y].empty()) {
				ans--;
			}
			g[x].insert(y);
			g[y].insert(x);
		}
		else {
			cin >> x;
			x--;
			
			for (auto v : g[x]) {
				g[v].erase(x);
				if (g[v].empty()) {
					ans++;
				}
			}
			if (!g[x].empty()) {
				ans++;
				g[x].clear();
			}
			
		}
		cout << ans << endl;
		
	}

}