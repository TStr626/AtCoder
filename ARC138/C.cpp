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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<long long> a(n);
	vector<pair<long long, long long>> b(n);
	rep(i, n) {
		cin >> a[i];
		b[i].first = a[i];
		b[i].second = i;
	}
	sort(b.begin(), b.end());
	ans = 0;
	rep(i, n / 2) {
		ans += b[n - 1 - i].first;
	}

	vector<long long> c(n), s(n + 1, 0);
	rep(i, n/2) {
		c[b[i].second] = 1;
	}
	rep(i, n / 2) {
		c[b[i+n/2].second] = -1;
	}
	rep(i, n) {
		s[i + 1] = s[i] + c[i];
	}
	res = 0; cur = 0;
	rep(i, n) {
		if (res > s[i]) {
			cur = i;
			res = s[i];
		}
	}
	cout << cur << ' ' << ans << endl;
}