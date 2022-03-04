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
	long long n, m, i, j, k, ans, cur, res, jud, mod = 998244353;
	cin >> n >> k;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	ans = 0; cur = 0; i = 0;
	vector<long long> p(n, -1), q(n, -1);
	long long cnt, lop;
	while (k > n) {
		res = ans % n;
		if (p[res] == -1) {
			q[res] = ans;
			p[res] = i;
			i++;
			ans += a[res];
			k--;
		}
		else {
			j = ans - q[res];
			cnt = i - p[res];
			lop = k / cnt;
			k %= cnt;
			ans += j * lop;
		}
	}

	while (k > 0) {
		res = ans % n;
		ans += a[res];
		k--;
	}
	cout << ans << endl;
}