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

struct ratio {
	long long dec;
	long long num;
	int i;
};
bool operator<(ratio a, ratio b) {
	if (a.dec * b.num != a.num * b.dec) {
		return a.dec * b.num > a.num * b.dec;
	}
	return a.i < b.i;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<ratio> r(n);
	rep(i, n) {
		cin >> x >> y;
		r[i].dec = x; r[i].num = x + y; r[i].i = i + 1;
	}
	sort(r.begin(), r.end());
	rep(i, n) {
		if (i) cout << ' ';
		cout << r[i].i;
	}
	cout << endl;
}