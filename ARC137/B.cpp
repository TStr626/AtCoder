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
	vector<long long> a(n),s(n+1,0);
	rep(i, n) {
		cin >> a[i];
	}
	s[0] = 0;
	ans = 1; cur = 0; res = 0;
	// increase
	rep(i, n) {
		if (a[i] == 0) {
			s[i + 1] = s[i] + 1;
		}
		else {
			s[i + 1] = s[i] - 1;
		}
		cur = min(s[i + 1], cur);
		res = max(res, s[i + 1] - cur);
	}
	ans += res;

	// decrease
	cur = 0; res = 0;
	rep(i, n) {
		if (a[i] == 1) {
			s[i + 1] = s[i] + 1;
		}
		else {
			s[i + 1] = s[i] - 1;
		}
		cur = min(s[i + 1], cur);
		res = max(res, s[i + 1] - cur);
	}
	ans += res;

	cout << ans << endl;
}