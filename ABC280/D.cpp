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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> k;
	cur = k;
	vector<pair<long long, long long>> vp(0);
	for (i = 2; i * i <= cur; i++) {
		if (cur % i > 0) {
			continue;
		}
		res = 0;
		while (cur % i == 0) {
			cur /= i;
			res++;
		}
		vp.push_back({ i,res });
	}
	if (cur > 1) {
		vp.push_back({ cur,1 });
	}

	ans = 1;
	rep(i, vp.size()) {
		cur = 0;
		res = vp[i].second;
		for (j = 1; res > 0; j++) {
			jud = vp[i].first * j;
			while (jud % vp[i].first == 0) {
				res--;
				jud /= vp[i].first;
			}
			if (res <= 0) {
				break;
			}
		}

		cur = vp[i].first * j;
		ans = max(ans, cur);
	}
	cout << ans << endl;
}