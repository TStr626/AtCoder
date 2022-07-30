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
	long long a, b;
	cin >> n >> a >> b;
	if (a <= b) {
		ans = max(0ll, n - (a - 1));
	}
	else {
		// b>a
		cur = (n + 1) / a;
		if (cur == 0) {
			ans = 0;
		}
		else {
			ans = min((n + 1) % a, b);
			ans += (cur - 1) * b;
		}
	}
	cout << ans << endl;

}