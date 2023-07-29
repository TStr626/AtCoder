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
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}
	rep(i, n - 8) {
		rep(j, m - 8) {
			jud = 1;
			rep(x, 3) {
				rep(y, 3) {
					if (s[i + x][j + y] != '#') {
						jud = 0;
					}
				}
			}
			for (x = 6; x < 9; x++) {
				for (y = 6; y < 9; y++) {
					if (s[i + x][j + y] != '#') {
						jud = 0;
					}
				}
			}
			x = 3;
			rep(y, 4) {
				if (s[i + x][j + y] != '.') {
					jud = 0;
				}
			}
			y = 3;
			rep(x, 4) {
				if (s[i + x][j + y] != '.') {
					jud = 0;
				}
			}
			x = 5;
			for (y = 5; y < 9; y++) {
				if (s[i + x][j + y] != '.') {
					jud = 0;
				}
			}
			y = 5;
			for (x = 5; x < 9; x++) {
				if (s[i + x][j + y] != '.') {
					jud = 0;
				}
			}
			if (jud) {
				cout << i + 1 << ' ' << j + 1 << endl;
			}
		}
	}
}