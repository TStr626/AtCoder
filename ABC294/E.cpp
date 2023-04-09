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
	long long l;
	cin >> l >> n >> m;
	vector<long long> a(n), la(n), b(m), lb(m);
	rep(i, n) {
		cin >> a[i] >> la[i];
	}
	rep(j, m) {
		cin >> b[j] >> lb[j];
	}
	x = la[0]; y = lb[0]; i = 0; j = 0;
	if (a[0] == b[0]) {
		ans = min(x, y);
	}
	else {
		ans = 0;
	}
	while (x < l || y < l) {
		if (x <= y) {
			i++;
			if (a[i] == b[j]) {
				ans += min(la[i], y - x);
			}
			x += la[i];
		}
		else {
			j++;
			if (a[i] == b[j]) {
				ans += min(lb[j], x - y);
			}
			y += lb[j];
		}
	}
	cout << ans << endl;
}