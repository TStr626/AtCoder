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
	long long query;
	cin >> n >> query;
	vector<long long> r(n), s(n + 1);
	rep(i, n) {
		cin >> r[i];
	}
	sort(r.begin(), r.end());
	rep(i, n) {
		s[i + 1] = s[i] + r[i];
	}
	while (query--) {
		cin >> k;
		ans = upper_bound(s.begin(), s.end(), k) - s.begin() - 1;
		cout << ans << endl;
	}
	

}