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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long d;
	cin >> n >> m >> d;
	vector<long long> a(n), b(m);
	rep(i, n) {
		cin >> a[i];
	}
	rep(j, m) {
		cin >> b[j];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	x = 0; y = 0; ans = -1;
	rep(i, n) {
		while (y < m && b[y] <= a[i] + d) {
			y++;
		}
		while (x < m && b[x] < a[i] - d) {
			x++;
		}
		if (x < y) {
			ans = max(ans, a[i] + b[y - 1]);
		}
	}
	cout << ans << endl;

}