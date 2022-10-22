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

struct fish {
	long long w;
	long long x;
	long long v;
};
bool operator<(fish a, fish b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.w < b.w;
}
struct eve {
	long long dec; // t=dec/num
	long long num;
	long long dif;
};
bool operator<(eve a, eve b) {
	if (a.dec * b.num != a.num * b.dec) {
		return a.dec * b.num < a.num* b.dec;
	}
	return a.dif > b.dif;
}
int main() {
	long long n, m, i, j, k, x, y, ans, cur, res, jud, mod, inf;
	long long a;
	cin >> n >> a;
	vector<fish> f(n);
	ans = 0;
	rep(i, n) {
		cin >> f[i].w >> f[i].x >> f[i].v;
		ans = max(ans, f[i].w);
	}
	sort(f.begin(), f.end());

	// t=0
	vector<vector<eve>> tsum(n, vector<eve>(0));
	eve ev;
	rep(i, n) {
		cur = 0;
		rep(j, n) {
			// t=0
			if (f[i].x <= f[j].x && f[j].x <= f[i].x + a) {
				cur += f[j].w;
			}
			// moving
			if (f[i].v == f[j].v) {
				continue;
			}
			if (f[i].v < f[j].v) {
				// j is faster
				if (f[j].x < f[i].x) {
					ev.dec = f[i].x - f[j].x;
					ev.num = f[j].v - f[i].v;
					ev.dif = f[j].w;
					tsum[i].push_back(ev);
				}
				if (f[j].x <= f[i].x + a) {
					ev.dec = f[i].x + a - f[j].x;
					ev.num = f[j].v - f[i].v;
					ev.dif = -f[j].w;
					tsum[i].push_back(ev);
				}
			}
			else {
				// i is faster
				if (f[j].x - a > f[i].x) {
					ev.dec = f[j].x - a - f[i].x;
					ev.num = f[i].v - f[j].v;
					ev.dif = f[j].w;
					tsum[i].push_back(ev);
				}
				if (f[j].x >= f[i].x) {
					ev.dec = f[j].x - f[i].x;
					ev.num = f[i].v - f[j].v;
					ev.dif = -f[j].w;
					tsum[i].push_back(ev);
				}
			}
		}

		ans = max(ans, cur);

		tsum[i].push_back({ 0,10000000001,0 });
		tsum[i].push_back({ 1,0,0 });
		sort(tsum[i].begin(), tsum[i].end());

		for (k = 0; k < tsum[i].size(); k++) {
			cur += tsum[i][k].dif;
			ans = max(ans, cur);
		}
		ans = max(ans, cur);
	}
	cout << ans << endl;
}