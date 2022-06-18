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

long long n;
vector<long long> a, b, c, d;

void recalc() {
	int i, cur, mod = 998244353;
	cur = 0;
	rep(i, n) {
		cur += a[i];
		cur %= mod;
		b[i] = cur;
	}
	cur = 0;
	rep(i, n) {
		cur += b[i];
		cur %= mod;
		c[i] = cur;
	}
	cur = 0;
	rep(i, n) {
		cur += c[i];
		cur %= mod;
		d[i] = cur;
	}
}


int main() {
	long long m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	long long query, t, v;
	cin >> query;
	a.resize(n);
	rep(i, n) {
		cin >> a[i];
	}
	b.resize(n);
	c.resize(n);
	d.resize(n);

	recalc();

	vector<long long> con(n + 1, 0);
	con[0] = 0;
	for (i = 1; i <= n; i++) {
		con[i] = (con[i - 1] + i) % mod;
	}

	vector<pair<long long, long long>> qu(0);
	
	while (query--) {
		cin >> t;
		if (t == 1) {
			cin >> x >> v;
			x--;
			qu.push_back({ x, v - a[x] });
			a[x] = v;
		}
		else {
			// t==2
			cin >> x;
			x--;

			m = qu.size();
			if (m * m <= n) {
				ans = d[x];
				rep(i, qu.size()) {
					cur = (qu[i].second * (con[max(0ll, x - qu[i].first + 1)])) % mod;
					ans = (ans + cur + mod) % mod;
				}
			}
			else {
				while (qu.size()) {
					qu.pop_back();
				}
				recalc();
				ans = d[x];
			}
			cout << ans << endl;
		}
	}

}