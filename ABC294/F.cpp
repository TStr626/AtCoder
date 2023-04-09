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

struct sw {
	long long s;
	long long w;
};
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> m >> k;
	vector<sw> a(n), b(m);
	rep(i, n) {
		cin >> a[i].s >> a[i].w;
	}
	rep(j, m) {
		cin >> b[j].s >> b[j].w;
	}
	double ok, ng, mid;
	vector<double> da(n), db(m + 1);
	ok = 0; ng = 1.0;
	while (ng - ok > 0.00000000000001) {
		mid = (ok + ng) / 2;
		rep(i, n) {
			da[i] = a[i].s - (a[i].w + a[i].s) * mid;
		}
		rep(j, m) {
			db[j] = b[j].s - (b[j].w + b[j].s) * mid;
		}
		db[m] = 10000000000;
		sort(da.begin(), da.end());
		sort(db.begin(), db.end());
		cur = 0;
		j = m;
		rep(i, n) {
			while (j && db[j - 1] + da[i] > 0) {
				j--;
			}
			cur += m - j;
		}
		if (cur >= k) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}
	cout << setprecision(11);
	cout << 100 * ok << endl;
}