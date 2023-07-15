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

long long n, m, ans = 0;
vector<long long> ct;
vector<vector<bool>> g;


void dfs(int r, int tm, int sp) {
	if (sp == r) {
		// fixed
		ans++;
		return;
	}
	

	int i, j, k = ct.size(), jud;
	
	rep(i, tm) {
		jud = 1;
		rep(j, k) {
			if (g[j][k] && (i == ct[j])) {
				// conflict
				jud = 0;
			}
		}
		if (jud == 0) {
			continue;
		}
		ct.push_back(i);
		dfs(r - 1, tm, sp);
		ct.pop_back();
	}
	if (sp == 0) {
		return;
	}
	ct.push_back(tm);
	dfs(r - 1, tm + 1, sp - 1);
	ct.pop_back();
}

int main() {
	long long i, j, k, h, w, x, y, cur, res, jud, mod;
	long long t;
	cin >> n >> t >> m;
	g.assign(n, vector<bool>(n, 0));
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		g[x][y] = g[y][x] = 1;
	}
	dfs(n, 0, t);
	cout << ans << endl;
}