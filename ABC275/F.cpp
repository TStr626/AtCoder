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

#define vl vector<long>
#define vvl vector<vl>
#define vvvl vector<vvl>

enum state {
	off=0,
	on=1,
};
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 1000000;
	cin >> n >> m;
	vl a(n);
	vvvl p(n + 1, vvl(m + 1, vl(2, inf)));
	long long sum = 0;
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}
	p[0][0][off] = 1; p[0][0][on] = 0;
	rep(i, n) {
		for (j = 0; j + a[i] <= m; j++) {
			p[i + 1][j + a[i]][on] = min(p[i][j][on], p[i][j][off]);
		}
		for (j = 0; j <= m; j++) {
			p[i + 1][j][off] = min(p[i][j][on] + 1, p[i][j][off]);
		}
	}
	for (i = 1; i <= m; i++) {
		ans = min(p[n][i][off], p[n][i][on]);
		if (ans == inf) {
			ans = -1;
		}
		cout << ans << endl;
	}
	
}