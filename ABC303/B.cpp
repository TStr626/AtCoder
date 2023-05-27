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
	vector<vector<bool>> p(n, vector<bool>(n, false));
	vector<long long> a(n);
	rep(j, m) {
		rep(i, n) {
			cin >> a[i];
			a[i]--;
		}
		rep(i, n - 1) {
			x = a[i]; y = a[i + 1];
			p[x][y] = p[y][x] = true;
		}
	}
	ans = 0;
	rep(i, n) {
		rep(j, i) {
			if (!p[i][j]) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	
}