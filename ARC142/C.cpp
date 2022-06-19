#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)


void ask(int u, int v) {
	cout << '?' << ' ' << u << ' ' << v << endl;
	return;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf = 1000000000;
	cin >> n;
	long long u, v;
	u = 0; v = 0;

	vector<long long> q1(n), q2(n);
	for (i = 2; i < n; i++) {
		ask(1, i + 1);
		cin >> q1[i];
	}
	for (i = 2; i < n; i++) {
		ask(2, i + 1);
		cin >> q2[i];
	}

	ans = n - 1; jud = 1;
	for (i = 2; i < n; i++) {
		if (abs(q1[i] - q2[i]) != 1) {
			jud = 0;
		}
		ans = min(ans, q1[i] + q2[i]);
	}

	if (ans == 3) {
		for (i = 2; i < n; i++) {
			if (q1[i] == 1 && q2[i] == 2) {
				u = i + 1;
			}
			if (q1[i] == 2 && q2[i] == 1) {
				v = i + 1;
			}
		}
		if (u > 0 && v > 0) {
			ask(u, v);
			cin >> res;
			if (res == 3) {
				ans = 1;
			}
		}
		else {
			ans = 1;
		}
	}

	cout << '!' << ' ' << ans << endl;
}