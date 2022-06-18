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
	long long n, m, i, j, k, x, y, ans, cur, res, jud, mod;
	vector<long long> h(3), w(3);
	long long curh, curw;
	curh = 0;
	rep(i, 3) {
		cin >> h[i];
		h[i] -= 3;
		curh += h[i];
	}
	curw = 0;
	rep(j, 3) {
		cin >> w[j];
		w[j] -= 3;
		curw += w[j];
	}
	if (curh != curw) {
		ans = 0;
		cout << ans << endl;
		return 0;
	}

	ans = 0;
	vector<long long> p(9);
	rep(p[0], min(h[0], w[0]) + 1) {
		rep(p[1], min(h[0], w[1]) + 1) {
			rep(p[3], min(h[1], w[0]) + 1) {
				rep(p[4], min(h[1], w[1]) + 1) {
					p[2] = h[0] - p[0] - p[1];
					p[5] = h[1] - p[3] - p[4];
					p[6] = w[0] - p[0] - p[3];
					p[7] = w[1] - p[1] - p[4];
					p[8] = h[2] - p[6] - p[7];
					
					cur = 100;
					cur = min(cur, p[2]);
					cur = min(cur, p[5]);
					cur = min(cur, p[6]);
					cur = min(cur, p[7]);
					cur = min(cur, p[8]);
					if (cur >= 0) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;

}