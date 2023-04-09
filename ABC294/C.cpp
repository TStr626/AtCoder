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

vector<int> compress(vector<int> a, int begin_value) {
	// need <map>,<algorithm>
	int i, n = a.size();
	map<int, int> mp;
	auto b = a;
	sort(b.begin(), b.end());
	int cur, res;
	res = b[0] - 1; cur = begin_value - 1;
	for (i = 0; i < n; i++) {
		if (b[i] > res) {
			res = b[i];
			cur++;
			mp[res] = cur;
		}
	}
	for (i = 0; i < n; i++) {
		b[i] = mp[a[i]];
	}
	return b;
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> m;
	vector<int> a(n), b(m), c(n + m);
	rep(i, n) {
		cin >> a[i];
		c[i] = a[i];
	}
	rep(j, m) {
		cin >> b[j];
		c[j + n] = b[j];
	}
	auto d = compress(c, 1);
	rep(i, n) {
		if (i)cout << ' ';
		cout << d[i];
	}
	cout << endl;
	rep(j, m) {
		if (j)cout << ' ';
		cout << d[n + j];
	}
	cout << endl;
}