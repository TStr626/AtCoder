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

double func(long long a, long long b, long long t) {
	return b * t + double(a) / sqrt(1 + t);
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long a, b;
	cin >> a >> b;

	long long l = 0, r = a / b + 1, m1, m2;
	while (r - l > 2) {
		m1 = (2 * l + r) / 3;
		m2 = (l + 2 * r) / 3;
		if (func(a, b, m1) < func(a, b, m2)) {
			r = m2;
		}
		else {
			l = m1;
		}
	}
	double ansd = func(a, b, l);
	cur = l + 1;
	while (cur <= r) {
		ansd = min(ansd, func(a, b, cur));
		cur++;
	}
	cout << fixed << setprecision(8);
	cout << ansd << endl;
}