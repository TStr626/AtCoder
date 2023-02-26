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
	vector<long long> vx(5 * n);
	rep(i, 5 * n) {
		cin >> vx[i];
	}
	sort(vx.begin(), vx.end());
	cur = 0;
	for (i = n; i < 4 * n; i++) {
		cur += vx[i];
	}
	double dans = double(cur) / (3 * n);
	cout << setprecision(7);
	cout << dans << endl;
}