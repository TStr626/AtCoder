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
	long long gx, gy;
	cin >> n >> gx >> gy;
	vector<long long> a(n);
	vector<vector<bool>> dpx(2, vector<bool>(20001, false));
	vector<bool> dpcur(20001);
	rep(i, n) {
		cin >> a[i];
	}
	dpx[0][10000 + a[0]] = true;
	dpx[1][10000] = true;
	for (i = 1; i < n; i++) {
		for (x = 0; x <= 20000; x++) {
			if (x - a[i] >= 0 && dpx[i % 2][x - a[i]]) {
				dpcur[x] = true;
			}
			else if (x + a[i] <= 20000 && dpx[i % 2][x + a[i]]) {
				dpcur[x] = true;
			}
			else {
				dpcur[x] = false;
			}
		}
		dpx[i % 2] = dpcur;
	}
	if (dpx[0][gx + 10000] && dpx[1][gy + 10000]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}