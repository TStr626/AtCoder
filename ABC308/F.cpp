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

struct voucher {
	long long l;
	long long d;
};
bool operator<(voucher a, voucher b) {
	if (a.l != b.l) {
		return a.l > b.l;
	}
	return a.d < b.d;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> m;
	vector<long long> p(n);
	ans = 0;
	rep(i, n) {
		cin >> p[i];
		ans += p[i];
	}
	
	vector<voucher> v(m + n);
	rep(j, m) {
		cin >> v[j].l;
	}
	rep(j, m) {
		cin >> v[j].d;
	}
	rep(i, n) {
		v[m + i].l = p[i];
		v[m + i].d = 0;
	}
	sort(v.begin(), v.end());

	multiset<long long> ms;
	cur = 0; res = 0;
	rep(i, m + n) {
		if (v[i].d == 0) {
			// item
			res++;
		}
		else {
			// voucher
			ms.insert(v[i].d);
			cur += v[i].d;
			res--;
			if (res == -1) {
				// voucher over used
				cur -= *ms.begin();
				ms.erase(ms.begin());
				res++;
			}
		}
	}
	cout << ans - cur << endl;

}