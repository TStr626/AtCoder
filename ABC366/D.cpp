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
	vector<vector<vector<long long>>> a(n + 1, vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)));
	rep(i, n) {
		rep(j, n) {
			rep(k, n) {
				cin >> a[i + 1][j + 1][k + 1];
			}
		}
	}
	rep(i, n+1) {
		rep(j, n+1) {
			rep(k, n) {
				a[i][j][k + 1] += a[i][j][k];
			}
		}
	}
	rep(i, n + 1) {
		rep(k, n + 1) {
			rep(j, n) {
				a[i][j + 1][k] += a[i][j][k];
			}
		}
	}
	rep(k, n + 1) {
		rep(j, n + 1) {
			rep(i, n) {
				a[i + 1][j][k] += a[i][j][k];
			}
		}
	}

	cin >> m;
	long long x1, x2, y1, y2, z1, z2;
	while (m--) {
		cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
		x1--; y1--; z1--;
		ans = a[x2][y2][z2] - a[x1][y2][z2] - a[x2][y1][z2] - a[x2][y2][z1]
			+ a[x1][y1][z2] + a[x1][y2][z1] + a[x2][y1][z1] - a[x1][y1][z1];
		cout << ans << endl;
	}
}