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

// TLE: multiset.count is dangerous

int main() {
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod = 998244353, inf = 1000000000000000000ll;
	cin >> n >> m;
	vector<long long> a(n), s(n - 1), x(m);
	rep(i, n - 1) {
		cin >> s[i];
	}
	rep(j, m) {
		cin >> x[j];
	}

	a[0] = 0;
	rep(i, n - 1) {
		a[i + 1] = s[i] - a[i];
	}
	/*
	rep(i, n) {
		cout << a[i] << ' ';
	}
	cout << endl;
	*/
	vector<multiset<long long>> ams(2);
	rep(i, n) {
		ams[i % 2].insert(a[i]);
	}

	ans = 0;
	rep(i, n) {
		rep(j, m) {
			if (i % 2 == 0) {
				res = x[j] - a[i];
			}
			else {
				res = a[i] - x[j];
			}

			cur = 0;
			rep(k, m) {
				cur += ams[0].count(x[k] - res) + ams[1].count(x[k] + res);
			}
			ans = max(cur, ans);
		}
	}
	cout << ans << endl;
}
