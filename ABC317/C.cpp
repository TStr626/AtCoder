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

struct ice {
	long long f;
	long long s;
};
bool operator<(ice a, ice b) {
	return a.s > b.s;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> m;
	vector<vector<long long>> d(n, vector<long long>(n, 0));
	rep(i, m) {
		cin >> x >> y >> k;
		x--; y--;
		d[x][y] = d[y][x] = k;
	}

	vector<long long> p(n);
	rep(i, n) {
		p[i] = i;
	}
	ans = 0;
	do {
		cur = 0;
		rep(i, n - 1) {
			if (d[p[i]][p[i + 1]] == 0) {
				// no path
				break;
			}
			cur += d[p[i]][p[i + 1]];
		}
		ans = max(ans, cur);
	} while (next_permutation(p.begin(), p.end()));
	cout << ans << endl;
}