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
	long long b;
	cin >> n >> k;
	vector<string> s(n);
	vector<vector<long long>> cnt(n, vector<long long>(26, 0));
	vector <long long> curcnt(26, 0);
	rep(i, n) {
		cin >> s[i];
		rep(j, s[i].size()) {
			cnt[i][s[i][j] - 'a']++;
		}
	}

	ans = 0;
	rep(b, (1ll << n)) {
		if (b == 0) continue;
		rep(j, 26) {
			curcnt[j] = 0;
		}
		cur = 0;

		rep(i, n) {
			if (b & (1ll << i)) {
				rep(j, 26) {
					curcnt[j] += cnt[i][j];
				}
			}
		}

		rep(j, 26) {
			if (curcnt[j] == k) {
				cur++;
			}
		}
		//cout << b << cur << endl;
		ans = max(ans, cur);
	}
	cout << ans << endl;
}