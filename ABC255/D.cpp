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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long query, ok, ng, mid;
	cin >> n >> query;
	vector<long long> a(n + 1), s(n + 2);
	rep(i, n) {
		cin >> a[i];
	}
	a[n] = 0;

	sort(a.begin(), a.end());
	s[0] = 0;
	rep(i, n + 1) {
		s[i + 1] = s[i] + a[i];
	}

	while (query--) {
		cin >> x;
		if (x > a[n]) {
			ans = x * n - s[n + 1];
		}
		else {
			ok = 0; ng = n + 1;
			while (ng - ok > 1) {
				mid = (ok + ng) / 2;
				if (a[mid] <= x) {
					ok = mid;
				}
				else {
					ng = mid;
				}
			}
			//cout << ok << endl;
			ans = (x * ok - s[ok + 1]) + ((s[n + 1] - s[ok + 1]) - x * (n - ok));
		}
		cout << ans << endl;
	}

}
