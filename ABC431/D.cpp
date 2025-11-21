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
	cin >> n;
	vector<long long> vw(n), vh(n), vb(n), vv(n);
	cur = res = 0;
	rep(i, n) {
		cin >> vw[i] >> vh[i] >> vb[i];
		vv[i] = max(0ll, vh[i] - vb[i]);
		cur += vb[i]; res += vw[i];
		vw[i] *= 2;
	}
	vector<long long> dp(res + 1, 0);
	rep(i, n) {
		for (j = res - vw[i]; j >= 0; j--) {
			dp[j + vw[i]] = max(dp[j + vw[i]], dp[j] + vv[i]);
		}
	}
	cout << cur + dp[res] << endl;
}