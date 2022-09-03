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

struct vert {
	long long cost;
	long long num;
};
bool operator<(vert a,vert b){
	if (a.cost != b.cost) {
		return a.cost < b.cost;
	}
	else {
		return a.num < b.num;
	}
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	vector<long long> a(n), c(n, 0);
	vector<vector<long long>> g(n, vector<long long>(0));
	rep(i, n) {
		cin >> a[i];
	}
	rep(j, m) {
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);

		c[x] += a[y];
		c[y] += a[x];
	}

	multiset<vert> ms;
	rep(i, n) {
		ms.insert({ c[i],i });
	}
	ans = 0;

	vert vcur, vres;
	auto itr = ms.begin();
	while (!ms.empty()) {
		itr = ms.begin();
		vcur = *itr;
		ms.erase(itr);
		ans = max(vcur.cost, ans);

		cur = vcur.num;
		c[cur] = 0;
		rep(j, g[cur].size()) {
			res = g[cur][j];
			if (c[res] == 0) {
				continue;
			}
			itr = ms.find({ c[res],res });
			vres = *itr;
			ms.erase(itr);
			c[res] -= a[cur];
			vres.cost -= a[cur];
			ms.insert(vres);
		}
	}
	cout << ans << endl;
}