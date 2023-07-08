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
	vector<vector<int>> a(n, vector<int>(n));
	char c;
	rep(i, n) {
		rep(j, n) {
			cin >> c;
			a[i][j] = (c == '1');
		}
	}
	vector<vector<int>> b(n, vector<int>(n));
	rep(i, n - 1) {
		b[i][0] = a[i + 1][0];
		b[i + 1][n - 1] = a[i][n - 1];
	}
	rep(j, n - 1) {
		b[0][j + 1] = a[0][j];
		b[n - 1][j] = a[n - 1][j + 1];
	}
	rep(i, n - 2) {
		rep(j, n - 2) {
			b[i + 1][j + 1] = a[i + 1][j + 1];
		}
	}
	rep(i, n) {
		rep(j, n) {
			cout << b[i][j];
		}
		cout << endl;
	}
}