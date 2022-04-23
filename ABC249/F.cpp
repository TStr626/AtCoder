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

struct query {
	long long t;
	long long y;
};
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n >> k;
	vector<query> qu(n + 1);
	qu[0].t = 1; qu[0].y = 0;
	rep(i, n) {
		cin >> qu[i + 1].t >> qu[i + 1].y;
	}

	multiset<long long> ms;
	auto itr = ms.begin();
	ans = -1000000000000000000ll; cur = 0; res = 0;
	for (i = n; i >= 0; i--) {
		if (qu[i].t == 2) {
			cur += qu[i].y;
			if (qu[i].y < 0) {
				ms.insert(-qu[i].y);
				res += qu[i].y;
			}
		}
		else {
			// qu[i].t == 1
			if (k < 0) break;

			while (ms.size() > k) {
				itr = ms.begin();
				res += *itr;
				ms.erase(itr);
			}
			if (ans < qu[i].y + cur - res) {
				ans = qu[i].y + cur - res;
			}
			/*
			itr = ms.begin();
			while (itr != ms.end()) {
				cout << *itr;
				itr++;
			}
			cout << endl;
			cout << qu[i].y << ' ' << cur << ' ' << res << endl;
			*/
			k--;
		}

	}
	cout << ans << endl;
}
