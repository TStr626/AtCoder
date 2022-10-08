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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 1000000000000000;
	cin >> n >> m;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}

	long long l, r;
	vector<set<long long>> ms(m);
	rep(i, n) {
		if (a[i] >= n - 1) {
			continue;
		}
		if (a[i] + (i + 1) * m < 0) {
			continue;
		}

		if (a[i] >= 0) {
			l = 1;
		}
		else {
			l = (-a[i] + i) / (i + 1);
		}

		for (j = l; j <= m && a[i] + (i + 1) * j < n; j++) {
			ms[j - 1].insert(a[i] + (i + 1) * j);
		}
	}

	rep(i, m) {
		ans = 0;
		while (ms[i].count(ans)) {
			ans++;
		}
		cout << ans << endl;
	}
}