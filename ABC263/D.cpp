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
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod = 998244353;
	long long l, r;
	cin >> n >> l >> r;
	vector<long long> a(n), sl(n + 1), sr(n + 1);
	rep(i, n) {
		cin >> a[i];
	}

	sl[0] = 0;
	rep(i, n) {
		sl[i + 1] = min(sl[i] + a[i], l * (i + 1));
	}

	sr[0] = 0;
	rep(i, n) {
		sr[i + 1] = min(sr[i] + a[(n - 1) - i], r * (i + 1));
	}

	ans = 1000000000000000000;
	rep(i, n + 1) {
		ans = min(ans, sl[i] + sr[n - i]);
	}
	cout << ans << endl;
	
}