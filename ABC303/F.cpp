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

struct mag {
	long long t;
	long long d;
};
bool dsort(mag a, mag b) {
	if (a.d != b.d) {
		return a.d > b.d;
	}
	return a.t > b.t;
}
struct pos {
	long long l;
	long long y;
	long long dy;
};
long long dif(long long a, long long y, long long dy){
	if (a == 0) {
		return 0;
	}
	long long up = 1000000000000000001;
	if (up / a < y) {
		return up;
	}
	if (dy > 0 && ((up / dy) < (a * (a - 1)) / 2)) {
		return up;
	}
	return a * y + (a * (a - 1)) / 2 * dy;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> h;
	vector<mag> mg(n);
	rep(i, n) {
		cin >> mg[i].t >> mg[i].d;
	}
	sort(mg.begin(), mg.end(), dsort);
	/*
	for (i = 0; i < n; i++) {
		cout << mg[i].t << ' ' << mg[i].d << endl;
	}
	*/
	vector<pos> p(0);
	p.push_back({ 1,mg[0].d ,mg[0].d });
	p.push_back({ mg[0].t,mg[0].d * mg[0].t,0 });
	cur = mg[0].d * mg[0].t;
	for (i = 1; i < n; i++) {
		if (mg[i].d * mg[i].t <= cur) {
			continue;
		}
		res = cur / mg[i].d + (cur % mg[i].d > 0);
		p.push_back({ res,mg[i].d * res,mg[i].d });
		p.push_back({ mg[i].t, mg[i].d * mg[i].t, 0 });
		cur = mg[i].d * mg[i].t;
	}
	
	ans = 0; cur = h;
	for (i = 0; i < p.size() - 1; i++) {
		res = p[i + 1].l - p[i].l;
		jud = dif(res, p[i].y, p[i].dy);
		if (cur > jud) {
			cur -= jud;
			ans += res;
			continue;
		}

		long long ok = res, ng = 0, mid;
		while (ok - ng > 1) {
			mid = (ok + ng) / 2;
			jud = dif(mid, p[i].y, p[i].dy);
			if (cur <= jud) {
				ok = mid;
			}
			else {
				ng = mid;
			}
		}
		ans += ok;
		cur = 0;
		break;
	}
	if (cur > 0) {
		ans += cur / p[p.size() - 1].y + (cur % p[p.size() - 1].y > 0);
	}
	cout << ans << endl;
	
}