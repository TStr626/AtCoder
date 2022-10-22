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
double distance(pos a, pos b) {
	long long dx = abs(a.x - b.x), dy = abs(a.y - b.y);
	return sqrt(dx * dx + dy * dy);
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 1000000000000000000;
	cin >> n >> m;
	vector<pos> p(n + m);
	rep(i, n + m) {
		cin >> p[i].x >> p[i].y;
	}
	vector<vector<double>> dist(n + m, vector<double>(n + m));
	vector<vector<double>> dp((1ll << (n + m)), vector<double>(n + m, inf));
	rep(i, n + m) {
		dist[i][i] = 0.0;
		for (j = i + 1; j < n + m; j++) {
			dist[i][j] = dist[j][i] = distance(p[i], p[j]);
		}
	}

	rep(i, n + m) {
		dp[(1 << i)][i] = distance({ 0,0 }, p[i]);
	}

	long long b;
	double sp;
	for (b = 1; b < (1ll << (n + m)); b++) {
		sp = 1.0;
		for (j = n; j < n + m; j++) {
			if (b & (1ll << j)) {
				sp *= 2.0;
			}
		}

		for (i = 0; i < (n + m); i++) {
			for (j = 0; j < (n + m); j++) {
				dp[(b | (1 << j))][j] = min(dp[b][i] + (dist[i][j] / sp), dp[(b | (1ll << j))][j]);
			}
		}
	}

	double ansd = inf;
	b = (1 << n) - 1;
	for (j = 0; j < (1 << m); j++) {
		sp = 1.0;
		for (k = n; k < (n + m); k++) {
			if (b & (1 << k)) {
				sp *= 2.0;
			}
		}
		for (i = 0; i < n; i++) {
			ansd = min(ansd, dp[b][i] + distance({ 0,0 }, p[i]) / sp);
		}
		for (k = n; k < (n + m); k++) {
			if (b & (1 << k)) {
				ansd = min(ansd, dp[b][k] + distance({ 0,0 }, p[k]) / sp);
			}
		}
		b += (1 << n);
	}
	cout << fixed << setprecision(8);
	cout << ansd << endl;
	
}