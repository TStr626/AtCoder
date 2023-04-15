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
	string s;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
	rep(i, n) {
		rep(j, n) {
			cin >> a[i][j];
		}
	}
	rep(i, n) {
		rep(j, n) {
			cin >> b[i][j];
		}
	}

	jud = 15;
	rep(i, n) {
		rep(j, n) {
			if (a[i][j] && !b[i][j]) {
				jud &= 14;
			}
			if (a[i][j] && !b[n - 1 - j][i]) {
				jud &= 13;
			}
			if (a[i][j] && !b[n - 1 - i][n - 1 - j]) {
				jud &= 11;
			}
			if (a[i][j] && !b[j][n - 1 - i]) {
				jud &= 7;
			}
		}
	}
	if (jud) {
		yes();
	}
	else {
		no();
	}
}