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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> m;
	vector<vector<long long>> g(n,vector<long long>(0));
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	rep(i, n) {
		cout << g[i].size();
		sort(g[i].begin(), g[i].end());
		rep(j, g[i].size()) {
			cout << ' ' << g[i][j] + 1;
		}
		cout << endl;
	}
}