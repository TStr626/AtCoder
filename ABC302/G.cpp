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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<vector<long long>> d(4, vector<long long>(4));
	vector<long long> a(n), b(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	rep(i, n) {
		d[a[i]][b[i]]++;
	}

	ans = 0;
	// pair
	rep(i, 4) {
		for (j = i + 1; j < 4; j++) {
			cur = min(d[i][j], d[j][i]);
			ans += cur;
			d[i][j] -= cur;
			d[j][i] -= cur;
		}
	}

	// triplet
	vector<long long> p(4);
	rep(i, 4) {
		p[i] = i;
	}
	do {
		cur = n;
		rep(i, 3) {
			cur = min(cur, d[p[i]][p[(i + 1) % 3]]);
		}
		ans += 2 * cur;
		rep(i, 3) {
			d[p[i]][p[(i + 1) % 3]] -= cur;
		}
	} while (next_permutation(p.begin(), p.end()));

	// quartet
	cur = 0;
	rep(i, 4) {
		rep(j, 4) {
			if (i == j) {
				continue;
			}
			cur += d[i][j];
		}
	}
	ans += cur / 4 * 3;

	cout << ans << endl;
}