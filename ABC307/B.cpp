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
	string t;
	rep(i, n) {
		rep(j, n) {
			if (i == j) {
				continue;
			}
			t = s[i] + s[j];
			m = t.size();
			jud = 1;
			rep(k, m / 2) {
				if (t[k] != t[m - 1 - k]) {
					jud = 0;
					break;
				}
			}
			if (jud) {
				yes();
				return 0;
			}
		}
	}
	no();
}