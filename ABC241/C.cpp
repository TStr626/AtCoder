#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
using namespace std;

# define rep(i,n) for(i=0; i<n; i++)


int main() {
	long long n, m, i, j, k, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}

	jud = 0;
	rep(i, n) {
		rep(j, n-5) {
			cur = 0;
			rep(k, 6) {
				if (s[i][j + k] == '#') {
					cur++;
				}
			}
			if (cur >= 4) {
				jud = 1;
			}
		}
	}
	rep(j, n) {
		rep(i, n - 5) {
			cur = 0;
			rep(k, 6) {
				if (s[i+k][j] == '#') {
					cur++;
				}
			}
			if (cur >= 4) {
				jud = 1;
			}
		}
	}
	rep(i, n-5) {
		rep(j, n - 5) {
			cur = 0;
			rep(k, 6) {
				if (s[i + k][j + k] == '#') {
					cur++;
				}
			}
			if (cur >= 4) {
				jud = 1;
			}
		}
	}
	rep(i, n - 5) {
		rep(j, n - 5) {
			cur = 0;
			rep(k, 6) {
				if (s[i + k][j + 5 - k] == '#') {
					cur++;
				}
			}
			if (cur >= 4) {
				jud = 1;
			}
		}
	}

	if (jud) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}