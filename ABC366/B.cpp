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
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}
	vector<int> a(n);
	a[0] = s[0].size();
	rep(i, n - 1) {
		a[i + 1] = max(a[i], int(s[i + 1].size()));
	}
	vector<string> sans(a[n - 1]);
	for (i = n - 1; i >= 0; i--) {
		for (j = 0; j < a[i]; j++) {
			if (j >= s[i].size()) {
				sans[j].push_back('*');
			}
			else {
				sans[j].push_back(s[i][j]);
			}
		}
	}
	rep(i, a[n - 1]) {
		cout << sans[i] << endl;
	}
}