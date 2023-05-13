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
	string s;
	cin >> s >> n;
	cur = 0;
	rep(i, s.size()) {
		if (s[i] == '?') {
			cur++;
		}
	}
	reverse(s.begin(), s.end());
	long long ok, ng, mid;
	ok = -1; ng = (1ll << cur);
	while (ng - ok > 1) {
		mid = (ng + ok) / 2;
		res = 0;
		jud = mid;
		rep(i, s.size()) {
			if (s[i] == '?') {
				if (jud & 1) {
					res += (1ll << i);
				}
				jud >>= 1;
			}
			else if (s[i] == '1') {
				res += (1ll << i);
			}
			else {
				//
			}
		}
		if (res <= n) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}
	if (ok == -1) {
		cout << -1 << endl;
		return 0;
	}
	rep(i, s.size()) {
		res = 0;
		jud = ok;
		rep(i, s.size()) {
			if (s[i] == '?') {
				if (jud & 1) {
					res += (1ll << i);
				}
				jud >>= 1;
			}
			else if (s[i] == '1') {
				res += (1ll << i);
			}
			else {
				//
			}
		}
	}
	cout << res << endl;
}