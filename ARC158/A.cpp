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
void solve() {
	vector<long long> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(), a.end());
	if ((a[0] + a[1]) % 2 || (a[0] + a[2]) % 2) {
		cout << -1 << endl;
		return;
	}
	a[1] -= a[0]; a[2] -= a[0]; a[0] = 0;
	a[1] /= 2; a[2] /= 2;
	if ((a[1] + a[2]) % 3) {
		cout << -1 << endl;
		return;
	}
	//cout << a[0] << a[1] << a[2] << endl;
	long long ans, cur;
	ans = 0;
	cur = min(a[1] - a[0], a[2] - a[1]);
	ans += cur;
	a[0] += 2 * cur; a[1] += cur;
	if (a[1] == a[2]) {
		cur = (a[1] - a[0]) / 3 * 2;
		ans += cur;
		//a[0] += cur * 3;
	}
	else {
		// a[0]==a[1]
		cur = (a[2] - a[1]) / 3 * 2;
		ans += cur;
	}
	//cout << ((a[2] - a[1]) + (a[2] - a[0])) / 3 << endl;
	cout << ans << endl;
	return;

}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long test;
	cin >> test;
	while (test--) {
		solve();
	}
	
}