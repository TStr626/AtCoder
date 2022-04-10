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
	cin >> n >> x >> y;
	vector<long long> a(n);
	vector<vector<long long>> p(1);
	j = 0;
	rep(i, n) {
		cin >> a[i];
		if (a[i] > x || a[i] < y) {
			if (p[j].size() > 0) {
				p.push_back({});
				j++;
			}
			else {
				// nothing
			}
		}
		else {
			p[j].push_back(a[i]);
		}
	}
	ans = 0;
	/*
	rep(i, p.size()) {
		rep(j, p[i].size()) {
			cout << p[i][j];
		}
		cout << endl;
	}
	*/
	long long cntx = 0, cnty = 0;
	rep(i, p.size()) {
		cntx = 0; cnty = 0; j = 0; k = 0; res = -1;
		while (k < p[i].size()) {
			if (p[i][k] == x) {
				cntx++;
			}
			if (p[i][k] == y) {
				cnty++;
			}
			
			if (min(cntx, cnty) > 0) {
				res = 1;
				while (min(cntx, cnty) > 0) {
					if (p[i][j] == x) {
						cntx--;
					}
					if (p[i][j] == y) {
						cnty--;
					}
					if (min(cntx, cnty) > 0) {
						res++;
					}
					j++;
				}
				ans += res * (p[i].size() - k);
				//cout << j << res << k << endl;
				res = -1;
				cntx = 0; cnty = 0;
				k = j - 1;
			}
			k++;
		}

	}
	cout << ans << endl;

}
