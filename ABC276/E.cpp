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

struct pos {
	long long x;
	long long y;
};
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> h >> w;
	long long sx, sy;
	vector<string> s(h);
	vector<vector<vector<bool>>> can(4, vector<vector<bool>>(h, vector<bool>(w, false)));
	rep(i, h) {
		cin >> s[i];
		rep(j, w) {
			if (s[i][j] == 'S') {
				sx = i; sy = j;
			}
		}
	}
	vector<long long> dx = { 1,-1,0,0 }, dy = { 0,0,1,-1 };
	queue<pos> qu;
	pos p;
	rep(k, 4) {
		if (min(sx + dx[k], sy + dy[k]) < 0 || sx + dx[k] >= h || sy + dy[k] >= w) {
			continue;
		}
		if (s[sx + dx[k]][sy + dy[k]] == '#') {
			continue;
		}
		qu.push({ sx + dx[k],sy + dy[k] });
		can[k][sx + dx[k]][sy + dy[k]] = true;

		while (qu.size()) {
			p = qu.front();
			x = p.x; y = p.y;
			qu.pop();
			rep(i, 4) {
				if (min(x + dx[i], y + dy[i]) < 0 || x + dx[i] >= h || y + dy[i] >= w) {
					continue;
				}
				if (s[x + dx[i]][y + dy[i]] != '.') {
					continue;
				}
				if (can[k][x + dx[i]][y + dy[i]] == true) {
					continue;
				}
				qu.push({ x + dx[i],y + dy[i] });
				can[k][x + dx[i]][y + dy[i]] = true;
			}
		}
	}

	rep(x, 4) {
		for (y = x + 1; y < 4; y++) {
			rep(i, h) {
				rep(j, w) {
					if (can[x][i][j] && can[y][i][j]) {
						cout << "Yes" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "No" << endl;
	
}