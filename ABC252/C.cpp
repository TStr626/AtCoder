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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf = 10000000;
	cin >> n;
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}

	ans = 10000000;

	char c;
	vector<long long> cnt(10);
	rep(x, 10) {
		c = '0' + x;
		rep(j, 10) {
			cnt[j] = 0;
		}
		rep(i, n) {
			rep(j, 10) {
				if (s[i][j] == c) {
					cnt[j]++;
				}
			}
		}

		cur = 0;
		rep(j, 10) {
			cur = max(cur, (cnt[j] - 1) * 10 + j);
		}
		//cout << cur << endl;
		ans = min(cur, ans);
	}
	cout << ans << endl;
}
