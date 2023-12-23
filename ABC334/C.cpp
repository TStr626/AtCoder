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
	cin >> n >> k;
	m = 2 * n - k;
	vector<long long> a(k);
	rep(i, k) {
		cin >> a[i];
		a[i]--;
	}
	vector<long long> s(m);
	j = 0; x = 0;
	rep(i, n) {
		if (j < k && a[j] == i) {
			// missing
			s[x] = i;
			j++;
			x++;
		}
		else {
			s[x] = i;
			x++;
			s[x] = i;
			x++;
		}
	}
	vector<long long> l(m / 2 + 1), r(m / 2 + 1);
	for (i = 1; i <= m / 2; i++) {
		l[i] = l[i - 1] + (s[2 * i - 1] - s[2 * i - 2]);
		r[i] = r[i - 1] + (s[m - 2 * i + 1] - s[m - 2 * i]);
	}
	ans = 1000000000000000000;
	for (i = 0; i <= m / 2; i++) {
		j = m / 2 - i;
		ans = min(ans, l[i] + r[j]);
	}
	cout << ans << endl;
}