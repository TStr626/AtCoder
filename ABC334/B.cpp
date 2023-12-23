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
void yes() {
	cout << "Yes" << endl;
}
void no() {
	cout << "No" << endl;
}
void vec_h(vector<long long> a) {
	int n = a.size(), i;
	rep(i, n) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
}
void vec_v(vector<long long> a) {
	for (auto c : a) {
		cout << c << endl;
	}
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long a, l, r, c, d;
	cin >> a >> m >> l >> r;
	l -= a; r -= a;
	if (0 < l) {
		ans = r / m - (l - 1) / m;
	}
	else if (r < 0) {
		l *= -1; r *= -1;
		swap(l, r);
		ans = r / m - (l - 1) / m;
	}
	else {
		ans = r / m + abs(l) / m + 1;
	}
	cout << ans << endl;
}