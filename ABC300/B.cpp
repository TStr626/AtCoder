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
	cin >> h >> w;
	vector<string> a(h), b(h);
	rep(i, h) {
		cin >> a[i];
	}
	rep(i, h) {
		cin >> b[i];
	}
	rep(i, h) {
		rep(j, w) {
			jud = 1;
			rep(x, h) {
				rep(y, w) {
					if (a[(i + x) % h][(j + y) % w] != b[x][y]) {
						jud = 0;
					}
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