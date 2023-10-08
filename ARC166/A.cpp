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
bool solve() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	string s,t;
	cin >> s >> t;
	x = 0; y = 0; j = 0;
	rep(i, n + 1) {
		if (t[i] == 'C' || i == n) {
			// valid C ?
			if (i < n && s[i] != 'C') {
				return false;
			}
			if (x < 0 || y < 0) {
				return false;
			}

			// valid B ?
			cur = 0;
			for (k = j; k < i; k++) {
				if (t[k] == 'B') {
					cur++;
				}
				if (s[k] == 'B') {
					cur--;
				}
				else if (s[k] == 'C') {
					if (x > 0) {
						x--;
					}
					else {
						cur--;
					}
				}
				if (cur < 0) {
					return false;
				}
			}

			// reset
			x = 0; y = 0; j = i + 1;
		}
		else {
			if (s[i] == 'A') {
				x--;
			}
			else if (s[i] == 'B') {
				y--;
			}
			if (t[i] == 'A') {
				x++;
			}
			else if (t[i] == 'B') {
				y++;
			}
		}
	}

	return true;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	while (n--) {
		solve() ? yes() : no();
	}
}