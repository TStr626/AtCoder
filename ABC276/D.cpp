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

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<long long> a(n), b(n);
	rep(i, n) {
		cin >> a[i];
	}
	cur = 0;
	rep(i, n) {
		cur = gcd(cur, a[i]);
	}
	ans = 0;
	rep(i, n) {
		b[i] = a[i] / cur;
		while (b[i] % 2 == 0) {
			b[i] /= 2;
			ans++;
		}
		while (b[i] % 3 == 0) {
			b[i] /= 3;
			ans++;
		}
		if (b[i] > 1) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
}