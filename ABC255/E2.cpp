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
	vector<vector<long long>> ams(2, vector<long long>(0));
	rep(i, n) {
		ams[i % 2].push_back(a[i]);
	}
	sort(ams[0].begin(), ams[0].end());
	sort(ams[1].begin(), ams[1].end());
	auto itr1 = ams[0].begin(), itr2 = ams[0].begin();

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
				itr1 = lower_bound(ams[0].begin(), ams[0].end(), x[k] - res);
				itr2 = upper_bound(ams[0].begin(), ams[0].end(), x[k] - res);
				cur += itr2 - itr1;
				itr1 = lower_bound(ams[1].begin(), ams[1].end(), x[k] + res);
				itr2 = upper_bound(ams[1].begin(), ams[1].end(), x[k] + res);
				cur += itr2 - itr1;
			}
			ans = max(cur, ans);
		}
	}
	cout << ans << endl;
}
