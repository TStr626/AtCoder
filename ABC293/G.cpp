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

struct query {
	long long num;
	long long l;
	long long r;
};
long long sqn;
bool operator<(query a, query b) {
	// mo's algorithm
	long long c = a.l / sqn, d = b.l / sqn;
	if (c != d) {
		return c < d;
	}
	return a.r < b.r;
}
int main() {
	
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}

	sqn = 1;
	while (sqn * sqn < n) {
		sqn++;
	}
	vector<query> vq(m);
	rep(i, m) {
		cin >> vq[i].l >> vq[i].r;
		vq[i].l--; vq[i].r;
		vq[i].num = i;
	}
	vector<long long> vans(m);
	sort(vq.begin(), vq.end());
	/*
	for (auto q : vq) {
		cout << q.l + 1 << ' ' << q.r + 1 << endl;
	}
	*/
	long long l = 0, r = 0;
	vector<long long> cnt(200001, 0);
	ans = 0;
	for (auto q : vq) {
		while (l < q.l) {
			// move l to right
			if (cnt[a[l]] >= 3) {
				res = cnt[a[l]];
				ans -= res * (res - 1) * (res - 2) / 6;
				ans += (res - 1) * (res - 2) * (res - 3) / 6;
			}
			cnt[a[l]]--;
			l++;
		}
		while (l > q.l) {
			// move l to left
			l--;
			if (cnt[a[l]] >= 2) {
				res = cnt[a[l]];
				ans -= res * (res - 1) * (res - 2) / 6;
				ans += (res + 1) * res * (res - 1) / 6;
			}
			cnt[a[l]]++;
		}

		while (r < q.r) {
			// move r to right
			if (cnt[a[r]] >= 2) {
				res = cnt[a[r]];
				ans -= res * (res - 1) * (res - 2) / 6;
				ans += (res + 1) * res * (res - 1) / 6;
			}
			cnt[a[r]]++;
			r++;
		}
		while (r > q.r) {
			r--;
			// move r to left
			if (cnt[a[r]] >= 3) {
				res = cnt[a[r]];
				ans -= res * (res - 1) * (res - 2) / 6;
				ans += (res - 1) * (res - 2) * (res - 3) / 6;
			}
			cnt[a[r]]--;
		}
		vans[q.num] = ans;
	}
	vec_v(vans);
}
	