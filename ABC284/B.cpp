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

void solve() {
	long long n, i, a, ans;
	cin >> n;
	ans = 0;
	rep(i, n) {
		cin >> a;
		ans += a % 2;
	}
	cout << ans << endl;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
}