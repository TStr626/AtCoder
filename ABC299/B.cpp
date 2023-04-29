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
	long long t;
	cin >> n >> t;
	vector<long long> c(n), r(n);
	rep(i, n) {
		cin >> c[i];
	}
	rep(i, n) {
		cin >> r[i];
	}
	ans = 0; cur = 0; res = r[0];
	rep(i, n) {
		if (c[i] == t && cur == 0) {
			cur = 1;
			res = r[i];
			ans = i;
		}
		if (cur == 0 && c[i] == c[0] && r[i] > res) {
			res = r[i];
			ans = i;
		}
		if (cur == 1 && c[i] == t && r[i] > res) {
			res = r[i];
			ans = i;
		}
	}
	cout << ans + 1 << endl;
}