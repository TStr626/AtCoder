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

struct lval {
	long long pos;
	long long val;
};

bool operator<(lval a, lval b) {
	if (a.val != b.val) {
		return a.val > b.val;
	}
	return a.pos < b.pos;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	map<long long, long long> mph, mpw;
	map<long long, vector<lval>> p;
	vector<long long> vx(n), vy(n), vr(n);
	rep(i, n) {
		cin >> vx[i] >> vy[i] >> vr[i];
		mph[vx[i]] += vr[i];
		mpw[vy[i]] += vr[i];
		p[vx[i]].push_back({ vy[i], vr[i] });
	}
	ans = 0;

	multiset<lval> ms;
	for (auto r : mpw) {
		ms.insert({ r.first,r.second });
	}

	lval l;
	for (auto r : mph) {
		// update
		x = r.first;
		for (auto c : p[x]) {
			y = c.pos;
			ms.erase({ y,mpw[y] });
			mpw[y] -= c.val;
			ms.insert({ y, mpw[y] });
		}

		// query
		res = ms.begin()->val;
		ans = max(res + mph[x], ans);

		// rollback
		for (auto c : p[x]) {
			y = c.pos;
			ms.erase({ y,mpw[y] });
			mpw[y] += c.val;
			ms.insert({ y, mpw[y] });
		}
	}
	cout << ans << endl;
}