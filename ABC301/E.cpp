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

struct pos {
	long long x;
	long long y;
};

bool operator<(pos a, pos b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.y < b.y;
}
long long popcount(long long x) {
	long long ans = 0, cur = x;
	while (cur) {
		ans += (cur & 1);
		cur >>= 1;
	}
	return ans;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long t;
	cin >> h >> w >> t;
	vector<string> a(h);
	rep(i, h) {
		cin >> a[i];
	}

	vector<pos> vp;
	map<pos, long long> mp;
	pos s, g, c;
	rep(i, h) {
		rep(j, w) {
			if (a[i][j] == 'S') {
				s.x = i; s.y = j;
			}
			else if (a[i][j] == 'G') {
				g.x = i; g.y = j;
			}
			else if (a[i][j] == 'o') {
				mp[{i, j}] = vp.size() + 1;
				vp.push_back({ i,j });
			}
		}
	}
	n = vp.size();
	mp[s] = n + 1;
	mp[g] = n + 2;
	vector<vector<long long>> d(n + 2, vector<long long>(n + 2, 1000000000000000000));
	vector<long long> dx = { 1,-1,0,0 }, dy = { 0,0,1,-1 };
	queue<pos> qu;
	rep(i, n + 2) {
		d[i][i] = 0;
	}
	
	vector<string> vs = a;
	qu.push(s);
	qu.push({ -1,-1 });
	cur = 0;
	vs[s.x][s.y] = '#';
	while (qu.size() != 1) {
		c = qu.front();
		qu.pop();
		if (c.x == -1) {
			qu.push({ -1,-1 });
			cur++;
			continue;
		}
		if (mp[c] > 0) {
			d[n][mp[c] - 1] = d[mp[c] - 1][n] = cur;
		}
		rep(k, 4) {
			if (c.x + dx[k] < 0 || c.x + dx[k] >= h || c.y + dy[k] < 0 || c.y + dy[k] >= w) {
				continue;
			}
			if (vs[c.x + dx[k]][c.y + dy[k]] == '#') {
				continue;
			}
			vs[c.x + dx[k]][c.y + dy[k]] = '#';
			qu.push({ c.x + dx[k],c.y + dy[k] });
		}
	}
	qu.pop();

	vs = a;
	qu.push(g);
	qu.push({ -1,-1 });
	cur = 0;
	vs[g.x][g.y] = '#';
	while (qu.size() != 1) {
		c = qu.front();
		qu.pop();
		if (c.x == -1) {
			qu.push({ -1,-1 });
			cur++;
			continue;
		}
		if (mp[c] > 0) {
			d[n + 1][mp[c] - 1] = d[mp[c] - 1][n + 1] = cur;
		}
		for (k = 0; k < 4; k++) {
			if (c.x + dx[k] < 0 || c.x + dx[k] >= h || c.y + dy[k] < 0 || c.y + dy[k] >= w) {
				continue;
			}
			if (vs[c.x + dx[k]][c.y + dy[k]] == '#') {
				continue;
			}
			vs[c.x + dx[k]][c.y + dy[k]] = '#';
			qu.push({ c.x + dx[k],c.y + dy[k] });
		}
	}
	qu.pop();

	rep(i, n) {
		vs = a;
		qu.push(vp[i]);
		qu.push({ -1,-1 });
		cur = 0;
		vs[vp[i].x][vp[i].y] = '#';
		while (qu.size() != 1) {
			c = qu.front();
			qu.pop();
			if (c.x == -1) {
				qu.push({ -1,-1 });
				cur++;
				continue;
			}
			if (mp[c] > 0) {
				d[i][mp[c] - 1] = d[mp[c] - 1][i] = cur;
			}
			for (k = 0; k < 4; k++) {
				if (c.x + dx[k] < 0 || c.x + dx[k] >= h || c.y + dy[k] < 0 || c.y + dy[k] >= w) {
					continue;
				}
				if (vs[c.x + dx[k]][c.y + dy[k]] == '#') {
					continue;
				}
				vs[c.x + dx[k]][c.y + dy[k]] = '#';
				qu.push({ c.x + dx[k],c.y + dy[k] });
			}
		}
		qu.pop();
	}

	// tsp
	long long inf = 1000000000000000000;
	vector<vector<long long>> dp((1ll << (n + 2)), vector<long long>(n + 2, inf));
	long long r = n, b;
	dp[(1 << r)][r] = 0;
	for (b = 0; b < (1 << (n+2)); b++) {
		for (i = 0; i < n+2; i++) {
			for (j = 0; j < n+2; j++) {
				dp[(b | (1 << j))][j] = min(dp[b][i] + d[i][j], dp[(b | (1 << j))][j]);
			}
		}
	}
	ans = -1;
	for (b = 0; b < (1 << (n)); b++) {
		if (dp[b + (1 << n) + (1 << n + 1)][n + 1] <= t) {
			ans = max(ans, popcount(b));
		}
	}
	cout << ans << endl;
	
}