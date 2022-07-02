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
	long long n, m, i, j, k, h, x, y, ans, cur, res, jud, mod;
	long long query, ok, ng, mid;
	cin >> n >> query >> x;
	vector<long long> w(n), s(2 * n + 1);
	rep(i, n) {
		cin >> w[i];
	}
	s[0] = 0;
	rep(i, 2 * n) {
		s[i + 1] = s[i] + w[i % n];
	}

	vector<vector<long long>> dbl(n, vector<long long>(61, 0));
	rep(i, n) {
		cur = x % s[n];
		ok = i; ng = i + n;
		while (ng - ok > 1) {
			mid = (ok + ng) / 2;
			if (s[mid] - s[i] >= cur) {
				ng = mid;
			}
			else {
				ok = mid;
			}
		}
		dbl[i][0] = (ok + 1) % n;
		//cout << dbl[i][0] << endl;
	}
	
	rep(j, 60) {
		rep(i, n) {
			dbl[i][j + 1] = dbl[dbl[i][j]][j];
		}
	}
	/*
	rep(i, n) {
		rep(j, 41) {
			cout << dbl[i][j];
		}
		cout << endl;
	}
	*/
	
	while (query--) {
		cin >> k;
		k--;

		i = 0; j = 0;
		while (k > 0) {
			if (k % 2) {
				i = dbl[i][j];
			}
			k /= 2;
			j++;
		}

		res = x / s[n];
		ans = res * n;

		cur = x % s[n];
		if (cur > 0) {
			ok = i; ng = i + n;
			while (ng - ok > 1) {
				mid = (ok + ng) / 2;
				if (s[mid] - s[i] >= cur) {
					ng = mid;
				}
				else {
					ok = mid;
				}
			}
			ans += ng - i;
		}

		cout << ans << endl;
	}
}