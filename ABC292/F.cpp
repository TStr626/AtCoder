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
	cin >> n >> m;
	if (n > m) {
		swap(n, m);
	}
	// n <= m
	double ok, ng, mid, the1, the2, pi = acos(-1.0);
	ok = n; ng = 10000.0;
	while (ng - ok > 0.000000000001) {
		mid = (ok + ng) / 2.0;
		the1 = acos(double(n)/ mid);
		the2 = pi / 6.0 - the1;
		//cout << mid << endl;
		//cout << the2 << endl;
		if (the2 < 0) {
			ng = mid;
			continue;
		}
		if (mid * cos(the2) <= m) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}
	cout << setprecision(16);
	cout << ok << endl;
}