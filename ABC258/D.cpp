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
	cin >> n >> x;
	vector<long long> a(n), b(n);
	rep(i, n) {
		cin >> a[i] >> b[i];
	}
	ans = 2000000000000000001ll;
	cur = 1000000000000000000ll;
	res = 0;
	rep(i, n) {
		res += a[i] + b[i];
		cur = min(cur, b[i]);
		ans = min(ans, res + cur * max(0ll, (x - i - 1)));
	}
	cout << ans << endl;
}