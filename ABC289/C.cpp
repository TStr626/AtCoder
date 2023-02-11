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
	cin >> n >> m;
	vector<long long> c(m);
	rep(i, m) {
		cin >> x;
		c[i] = 0;
		rep(j, x) {
			cin >> y;
			c[i] += (1 << (y - 1));
		}
	}
	ans = 0; cur = (1 << n) - 1;
	for (x = 1; x < (1 << m); x++) {
		res = 0;
		rep(i, m) {
			if (x & (1 << i)) {
				res |= c[i];
			}
		}
		if (cur == res) {
			ans++;
		}
	}
	cout << ans << endl;
}