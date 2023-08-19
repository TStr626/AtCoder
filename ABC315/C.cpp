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

struct ice {
	long long f;
	long long s;
};
bool operator<(ice a, ice b) {
	return a.s > b.s;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<ice> v(n);
	rep(i, n) {
		cin >> v[i].f >> v[i].s;
	}
	sort(v.begin(), v.end());
	ans = 0;
	rep(i, n - 1) {
		if (v[i + 1].f == v[0].f) {
			ans = max(ans, v[i + 1].s / 2 + v[0].s);
		}
		else {
			ans = max(ans, v[i + 1].s + v[0].s);
		}
	}
	cout << ans << endl;
}