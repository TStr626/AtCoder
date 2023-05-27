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
	string s,t;
	cin >> s >> t;
	rep(i, n) {
		if (s[i] == t[i]) {
			continue;
		}
		if (s[i] == '1' && t[i] == 'l') {
			continue;
		}
		if (s[i] == 'l' && t[i] == '1') {
			continue;
		}
		if (s[i] == '0' && t[i] == 'o') {
			continue;
		}
		if (s[i] == 'o' && t[i] == '0') {
			continue;
		}
		no();
		return 0;
	}
	yes();
	return 0;
}