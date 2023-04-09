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

map<long long, int> mp;
bool isprime(long long x) {
	// note: 1 is prime in this code
	if (mp[x]) {
		return mp[x] == 1;
	}
	long long i;
	if (x == 1) {
		mp[x] = 1;
		return true;
	}
	for (i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			mp[x] = 2;
			return false;
		}
	}
	mp[x] = 1;
	return true;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> x >> y;
	if (x < y) {
		swap(x, y);
	}
	ans = 0; cur = x - y;
	
	if (x == y) {
		cout << 1 << endl;
		return 0;
	}
	while (y > 0) {
		res = gcd(x, y);
		x /= res; y /= res; cur /= res;
		if (isprime(cur)) {
			ans += y % cur;
			ans += y / cur;
			break;
		}
		else {
			ans++;
			x--;
			y--;
		}
		//cout << x << ' ' << y << ' ' << ans << endl;
	}
	cout << ans << endl;

}