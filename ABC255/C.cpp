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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf = 10000000;
	long long a, d;
	cin >> x >> a >> d >> n;
	if (d == 0) {
		ans = abs(a - x);
		cout << ans << endl;
		return 0;
	}
	
	if (d < 0) {
		a = a + d * (n - 1);
		d = -d;
	}

	if (x <= a) {
		ans = abs(x - a);
	}
	else if (x >= a + d * (n - 1)) {
		ans = abs(x - (a + d * (n - 1)));
	}
	else {
		ans = (x - a) % d;
		ans = min(ans, d - ans);
	}
	cout << ans << endl;
}
