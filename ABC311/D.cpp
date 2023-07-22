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

struct pos {
	long long x;
	long long y;
	long long dx;
	long long dy;
};

int main() {
	long long i, j, k, h, w, x, y, cur, res, jud, mod;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}

	vector<vector<vector<pos>>> vp(n, vector<vector<pos>>(m, vector<pos>(0)));
	
	/*
	for (j = 1; j < m - 1; j++) {
		p.y = j;
		// to up
		for (i = 0; i < n; i++) {
			if (s[i][j] == '#') {
				p.x = i + 1;
			}
			else {
				vp[i][j].push_back(p);
			}
		}
		// to down
		for (i = n - 1; i >= 0; i--) {
			if (s[i][j] == '#') {
				p.x = i - 1;
			}
			else {
				vp[i][j].push_back(p);
			}
		}
	}

	for (i = 1; i < n - 1; i++) {
		p.x = i;
		// to left
		for (j = 0; j < n; j++) {
			if (s[i][j] == '#') {
				p.y = j + 1;
			}
			else {
				vp[i][j].push_back(p);
			}
		}
		// to right
		for (j = n - 1; j >= 0; j--) {
			if (s[i][j] == '#') {
				p.y = j - 1;
			}
			else {
				vp[i][j].push_back(p);
			}
		}
	}
	*/
	queue<pos> qu;
	qu.push({ 1,1,1,0 });
	qu.push({ 1,1,0,1 });
	vector<vector<bool>> checked(n, vector<bool>(m, false)), moved(n, vector<bool>(m, false));
	vector<long long> dx = { 1,-1,0,0 }, dy = { 0,0,1,-1 };
	checked[1][1] = true;
	moved[1][1] = true;
	ans = 1;
	pos p, pa;
	while (qu.size()) {
		p = qu.front();
		qu.pop();
		pa.x = p.x + p.dx; pa.y = p.y + p.dy;
		if (s[pa.x][pa.y] == '.') {
			// continue
			pa.dx = p.dx; pa.dy = p.dy;
			qu.push(pa);
			if (checked[pa.x][pa.y] == false) {
				checked[pa.x][pa.y] = true;
				ans++;
			}
			continue;
		}
		else {
			// stop
			if (moved[p.x][p.y] == true) {
				continue;
			}
			moved[p.x][p.y] = true;
			rep(k, 4) {
				p.dx = dx[k];
				p.dy = dy[k];
				qu.push(p);
			}
		}
	}
	cout << ans << endl;
	
}