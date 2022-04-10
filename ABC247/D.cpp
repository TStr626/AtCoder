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
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod;
	long long query, t, x, c;
	cin >> query;
	vector<pair<long long, long long>> vp(0);
	i = 0;
	while (query--) {
		cin >> t;
		if (t == 1) {
			cin >> x >> c;
			vp.push_back({ x,c });
		}
		else {
			// t==2
			cin >> c;
			ans = 0;
			while (c > 0) {
				if (vp[i].second == 0) {
					i++;
				}
				cur = min(c, vp[i].second);
				ans += vp[i].first * cur;
				c -= cur;
				vp[i].second -= cur;
			}
			cout << ans << endl;
		}
	}
}