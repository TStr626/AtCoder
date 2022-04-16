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
// WA:why?
struct pos {
	long long x;
	long long y;
};

bool sameline(pos a, pos b, pos c) {
	long long x1, x2, y1, y2;
	x1 = b.x - a.x;
	x2 = c.x - a.x;
	y1 = b.y - a.y;
	y2 = c.y - a.y;
	return x2 * y1 == x1 * y2;
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf = 10000000;
	cin >> n >> k;
	vector<pos> p(n);
	rep(i, n) {
		cin >> p[i].x >> p[i].y;
	}
	// valid check
	if (k == 1) {
		cout << "Infinity" << endl;
		return 0;
	}
	else {
		vector<vector<bool>> check(n, vector<bool>(n, false));
		ans = 0;
		rep(i, n) {
			for (j = i + 1; j < n; j++) {
				if (check[i][j] == true) {
					continue;
				}

				cur = 2;
				for (w = j + 1; w < n; w++) {
					if (sameline(p[i], p[j], p[w])) {
						//cout << i << j << w << endl;
						check[i][w] = true;
						check[j][w] = true;
						cur++;
					}
				}
				if (cur >= k) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
