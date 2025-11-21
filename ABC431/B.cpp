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
	cin >> x >> n;
	vector<long long> vw(n);
	rep(i, n) {
		cin >> vw[i];
	}
	cin >> m;
	ans = x;
	vector<bool> vb(n);
	rep(j, m) {
		cin >> y;
		y--;
		if (vb[y]) {
			// remove
			ans -= vw[y];
			vb[y] = 0;
		}
		else {
			// attach
			ans += vw[y];
			vb[y] = 1;
		}

		cout << ans << endl;
	}

}