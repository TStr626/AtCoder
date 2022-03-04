#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)

int main() {
	int n, m, i, j, k, t, ans, cur, res, jud, mod = 998244353;
	int h, w, sx, sy, gx, gy, curx, cury, resx, resy;
	cin >> h >> w >> n;
	cin >> sx >> sy >> gx >> gy;
	vector<int> x(n), y(n);
	map<int, set<int>> u, d, l, r;
	map<pair<int, int>, int> dis;
	queue<pair<int, int>> qu;
	pair<int, int> p;
	rep(i, n) {
		cin >> x[i] >> y[i];
		u[y[i]].insert(-(x[i] + 1));
		d[y[i]].insert(x[i] - 1);
		l[x[i]].insert(-(y[i] + 1));
		r[x[i]].insert(y[i] - 1);
	}
	
	auto itr = u[y[0]].begin();
	dis[{sx, sy}] = 1;
	qu.push({ sx,sy });
	
	while (!qu.empty()) {
		p = qu.front();
		curx = p.first; cury = p.second;
		cur = dis[p];
		qu.pop();
		
		itr = u[cury].lower_bound(-curx);
		if (itr != u[cury].end()) {
			resx = -*itr; resy = cury; res = cur + 1;
			if (dis[{resx, resy}] == 0) {
				dis[{resx, resy}] = res;
				qu.push({ resx,resy });
			}
		}
		
		itr = d[cury].lower_bound(curx);
		if (itr != d[cury].end()) {
			resx = *itr; resy = cury; res = cur + 1;
			if (dis[{resx, resy}] == 0) {
				dis[{resx, resy}] = res;
				qu.push({ resx,resy });
			}
		}
		
		itr = l[curx].lower_bound(-cury);
		if (itr != l[curx].end()) {
			resx = curx; resy = -*itr; res = cur + 1;
			if (dis[{resx, resy}] == 0) {
				dis[{resx, resy}] = res;
				qu.push({ resx,resy });
			}
		}

		itr = r[curx].lower_bound(cury);
		if (itr != r[curx].end()) {
			resx = curx; resy = *itr; res = cur + 1;
			if (dis[{resx, resy}] == 0) {
				dis[{resx, resy}] = res;
				qu.push({ resx,resy });
			}
		}
		
		
	}

	ans = dis[{gx, gy}] - 1;
	cout << ans << endl;
	
}