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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf;
	long long z;
	cin >> x >> y >> z;
	if (x < 0) {
		x = -x; y = -y; z = -z;
	}

	if (y < 0 || x < y) {
		ans = x;
	}
	else if (0 < z && z < y && y < x) {
		ans = x;
	}
	else if (z < 0 && 0 < y && y < x) {
		ans = x - 2 * z;
	}
	else {
		ans = -1;
	}
	cout << ans << endl;
}