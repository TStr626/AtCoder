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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) {
		cin >> s[i];
	}

	vector<long long> c(4);
	cur = 0;
	rep(i, h) {
		rep(j, w) {
			if (s[i][j] == 'o') {
				if (cur == 0) {
					c[0] = i;
					c[1] = j;
					cur = 1;
				}
				else {
					c[2] = i;
					c[3] = j;
				}
			}
		}
	}
	ans = abs(c[0] - c[2]) + abs(c[1] - c[3]);
	cout << ans << endl;
}