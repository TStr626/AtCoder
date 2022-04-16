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
	cin >> n;
	vector<long long> a(n);
	vector<vector<long long>> cnt(n, vector<long long>(1, -1));
	rep(i, n) {
		cin >> a[i];
		a[i]--;
		cnt[a[i]].push_back(i);
	}

	long long query, l, r, x, ok, ng, mid, itrl, itrr;
	cin >> query;
	while (query--) {
		cin >> l >> r >> x;
		l--; x--;
		
		ok = 0; ng = cnt[x].size();
		while (ng - ok > 1) {
			mid = (ok + ng) / 2;
			if (cnt[x][mid] < l) {
				ok = mid;
			}
			else {
				ng = mid;
			}
		}
		itrl = ok;

		ok = 0; ng = cnt[x].size();
		while (ng - ok > 1) {
			mid = (ok + ng) / 2;
			if (cnt[x][mid] < r) {
				ok = mid;
			}
			else {
				ng = mid;
			}
		}
		itrr = ok;
		cout << itrr - itrl << endl;
	}
}