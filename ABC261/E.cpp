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
	long long n, m, i, j, k, h, w, y, ans, cur, res, jud, mod;
	long long c;
	cin >> n >> c;
	vector<long long> t(n);
	vector<vector<long long>> a(n, vector<long long>(30, 0));
	rep(i, n) {
		cin >> t[i] >> y;
		rep(j, 30) {
			a[i][j] = y % 2;
			y /= 2;
		}
	}

	vector<vector<bool>> forced(n + 1, vector<bool>(30, false));
	vector<vector<long long>> xored(n + 1, vector<long long>(30, false));
	rep(i, n) {
		rep(j, 30) {
			forced[i + 1][j] = forced[i][j];
			xored[i + 1][j] = xored[i][j];
			if (t[i] == 1 && a[i][j] == 0) {
				forced[i + 1][j] = true;
				xored[i + 1][j] = 0;
			}
			if (t[i] == 2 && a[i][j] == 1) {
				forced[i + 1][j] = true;
				xored[i + 1][j] = 1;
			}
			if (t[i] == 3 && a[i][j] == 1) {
				xored[i + 1][j] ^= 1;
			}
		}
	}

	cur = c;
	rep(i, n) {
		ans = 0;
		rep(j, 30) {
			if (forced[i + 1][j] == true) {
				ans += xored[i + 1][j] * (1ll << j);
			}
			else {
				ans += cur & (1ll << j);
				if (xored[i + 1][j] == 1) {
					ans ^= (1ll << j);
				}
			}
			
		}
		cout << ans << endl;
		cur = ans;
	}
}