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
	long long n, m, i, j, k, h, w, x, y, z, ans, cur, res, jud, mod;
	cin >> n >> m;
	vector<long long> a(n), s(n + 1);
	s[0] = 0;
	rep(i, n) {
		cin >> a[i];
		s[i + 1] = s[i] + a[i];
	}

	cur = 0;
	rep(j, m) {
		cur += (j + 1) * a[j];
	}
	ans = cur;
	//cout << cur << endl;

	for (i = 0; i < n - m; i++) {
		cur += m * a[i + m];
		cur -= s[i + m] - s[i];
		//cout << cur << endl;
		ans = max(ans, cur);
	}
	cout << ans << endl;
}