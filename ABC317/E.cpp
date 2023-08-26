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
bool isWall(char c) {
	return c == '#' || c == '>' || c == '<' || c == '^' || c == 'v';
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> h >> w;
	pos s, g, p, q;
	vector<string> a(h);
	rep(i, h) {
		cin >> a[i];
		rep(j, w) {
			if (a[i][j] == 'S') {
				s.x = i; s.y = j;
			}
			if (a[i][j] == 'G') {
				g.x = i; g.y = j;
			}
		}
	}

	vector<vector<long long>> wall(h, vector<long long>(w, 0));
	// right check
	rep(i, h) {
		res = 0;
		rep(j, w) {
			if (isWall(a[i][j])) {
				res = 0;
				wall[i][j] = 1;
			}
			else {
				wall[i][j] |= res;
			}
			if (a[i][j] == '>') {
				res = 1;
			}
		}
	}
	// left check
	rep(i, h) {
		res = 0;
		for (j = w - 1; j >= 0; j--) {
			if (isWall(a[i][j])) {
				res = 0;
				wall[i][j] = 1;
			}
			else {
				wall[i][j] |= res;
			}
			if (a[i][j] == '<') {
				res = 1;
			}
		}
	}
	// down check
	rep(j, w) {
		res = 0;
		rep(i, h) {
			if (isWall(a[i][j])) {
				res = 0;
				wall[i][j] = 1;
			}
			else {
				wall[i][j] |= res;
			}
			if (a[i][j] == 'v') {
				res = 1;
			}
		}
	}
	// up check
	rep(j, w) {
		res = 0;
		for (i = h - 1; i >= 0; i--) {
			if (isWall(a[i][j])) {
				res = 0;
				wall[i][j] = 1;
			}
			else {
				wall[i][j] |= res;
			}
			if (a[i][j] == '^') {
				res = 1;
			}
		}
	}

	vector<long long> dx = { 1,-1,0,0 }, dy = { 0,0,1,-1 };
	queue<pos> qu;
	vector<vector<long long>> d(h, vector<long long>(w, h* w));
	qu.push(s);
	d[s.x][s.y] = 0;
	while (qu.size()) {
		p = qu.front();
		qu.pop();
		rep(k, 4) {
			q.x = p.x + dx[k];
			q.y = p.y + dy[k];
			// out of range
			if (min(q.x, q.y) < 0 || q.x >= h || q.y >= w) {
				continue;
			}
			// wall
			if (wall[q.x][q.y]) {
				continue;
			}
			// already passed
			if (d[q.x][q.y] <= d[p.x][p.y] + 1) {
				continue;
			}
			qu.push(q);
			d[q.x][q.y] = d[p.x][p.y] + 1;
		}
	}
	if (d[g.x][g.y] == h * w) {
		d[g.x][g.y] = -1;
	}
	cout << d[g.x][g.y] << endl;
	/*
	rep(i, h) {
		rep(j, w) {
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
	*/
}