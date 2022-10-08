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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 1000000000;
	cin >> n >> m;
	vector<vector<long long>> check(n, vector<long long>(n, -1));

	vector<pos> move(0);
	j = floor(sqrt(m + 1));
	for (i = 0; i * i <= m; i++) {
		while (j * j > m - i * i) {
			j--;
		}
		if (i * i + j * j == m && i <= j) {
			move.push_back({ i,j });
			move.push_back({ -i,-j });
			move.push_back({ -i,j });
			move.push_back({ i,-j });
			if (i != j) {
				move.push_back({ j,i });
				move.push_back({ -j,-i });
				move.push_back({ -j,i });
				move.push_back({ j,-i });
			}
		}
	}

	queue<pos> qu;
	check[0][0] = 0;
	qu.push({ 0,0 });
	pos p;
	long long dx, dy;
	while (qu.size()) {
		p = qu.front();
		x = p.x;
		y = p.y;
		cur = check[x][y];
		rep(i, move.size()) {
			dx = move[i].x;
			dy = move[i].y;
			if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < n) {
				if (check[x + dx][y + dy] == -1) {
					check[x + dx][y + dy] = cur + 1;
					qu.push({ x + dx,y + dy });
				}
			}
		}
		qu.pop();
	}
	
	rep(i, n) {
		rep(j, n) {
			if (j) cout << ' ';
			cout << check[i][j];
		}
		cout << endl;
	}
}