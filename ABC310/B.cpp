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
	vector<long long> p(n);
	vector<vector<bool>> b(n, vector<bool>(m, 0));
	rep(i, n) {
		cin >> p[i] >> x;
		rep(j, x) {
			cin >> y;
			y--;
			b[i][y] = 1;
		}
	}

	rep(i, n) {
		rep(j, n) {
			if (i == j) {
				continue;
			}
			if (p[i] < p[j]) {
				continue;
			}
			cur = 1; res = 0;
			rep(k, m) {
				if (b[i][k] && !b[j][k]) {
					cur = 0;
				}
				if (!b[i][k] && b[j][k]) {
					res = 1;
				}
			}
			if (cur && (res || p[i] > p[j])) {
				yes();
				return 0;
			}
		}
	}
	no();
}