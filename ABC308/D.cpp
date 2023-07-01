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
	long long c;
};

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) {
		cin >> s[i];
	}
	string r = "snuke";
	m = 5;
	vector<vector<bool>> d(h, vector<bool>(w, false));
	vector<long long> dx = { 1,-1,0,0 }, dy = { 0,0,1,-1 };
	queue<pos> qu;
	if (s[0][0] != 's') {
		no();
		return 0;
	}
	qu.push({ 0,0,0 });
	d[0][0] = true;
	pos p;
	long long c;
	while (qu.size()) {
		p = qu.front();
		qu.pop();
		rep(k, 4) {
			x = p.x + dx[k];
			y = p.y + dy[k];
			c = (p.c + 1) % m;
			if (min(x, y) < 0 || x >= h || y >= w) {
				// out of range
				continue;
			}
			if (s[x][y] != r[c]) {
				// wrong letter
				continue;
			}
			if (d[x][y] == true) {
				// already checked
				continue;
			}
			// update
			qu.push({ x,y,c });
			d[x][y] = true;
		}
	}
	/*
	rep(i, h) {
		rep(j, w) {
			cout << d[i][j];
		}
		cout << endl;
	}
	*/
	if (d[h - 1][w - 1] == true) {
		yes();
	}
	else {
		no();
	}

}