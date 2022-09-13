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
	if (a == 0) {
		return b;
	}
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	vector<long long> b(n);
	rep(i, n - 1) {
		a[i + 1] -= a[0];
	}
	a[0] = 0;

	cur = 0;
	rep(i, n) {
		//cout << a[i];
		cur = gcd(cur, a[i]);
	}

	//cout << cur << endl;
	if (cur == 1) {
		ans = 2;
	}
	else {
		ans = 1;
	}
	cout << ans << endl;
}