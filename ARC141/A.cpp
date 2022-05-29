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

long long pow10(long long n) {
	long long ans = 1, cur = n;
	while (cur--) {
		ans *= 10;
	}
	return ans;
}

long long digit(long long n) {
	long long ans = 1, cur = n;
	while (cur >= 10) {
		cur /= 10;
		ans++;
	}
	return ans;
	
}

long long check(long long n, long long cnt) {
	long long i, ans = n;
	for (i = 1; i < cnt; i++) {
		ans = ans * pow10(digit(n)) + n;
	}
	return ans;
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf=1100000000;
	long long test, ok, ng, mid, cnt;
	cin >> test;
	while (test--) {
		cin >> n;
		ans = 0;
		for (cnt = 2; cnt <= 18; cnt++) {
			ok = 0; ng = pow10(18 / cnt);
			while (ng - ok > 1) {
				mid = (ok + ng) / 2;
				cur = check(mid, cnt);
				if (cur <= n) {
					ok = mid;
				}
				else {
					ng = mid;
				}
			}
			res = check(ok, cnt);
			//cout << res << endl;
			ans = max(ans, res);
		}
		cout << ans << endl;
	}
	
}