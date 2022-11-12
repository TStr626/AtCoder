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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> m;
	vector<long long> a(n);
	map<long long,long long> cnt;

	res = 0;
	rep(i, n) {
		cin >> a[i];
		res += a[i];
		cnt[a[i]]++;
	}

	sort(a.begin(), a.end());
	rep(i, n) {
		a.push_back(a[i]);
	}

	ans = 0; i = 1; cur = a[0];
	while (i < 2 * n) {
		if (a[i - 1] == a[i] || (a[i - 1] + 1) % m == a[i]) {
			cur += a[i];
		}
		else {
			cur = a[i];
		}
		ans = max(ans, cur);
		i++;
	}


	ans = max(0ll, res - ans);
	cout << ans << endl;
}