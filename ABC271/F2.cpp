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
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod = 998244353, inf;

	cin >> n;
	vector<vector<long long>> a(n, vector<long long>(n));
	vector<vector<long long>> b(n, vector<long long>(n));
	vector<vector<map<long long, long long>>> dpa(n, vector<map<long long, long long>>(n));
	vector<vector<map<long long, long long>>> dpb(n, vector<map<long long, long long>>(n));
	rep(i, n) {
		rep(j, n) {
			cin >> a[i][j];
			b[n - 1 - i][n - 1 - j] = a[i][j];
		}
	}

	dpa[0][0][a[0][0]] = 1;
	auto itr = dpa[0][0].begin();
	rep(i, n - 1) {
		rep(j, n - 1 - i) {
			for (itr = dpa[i][j].begin(); itr != dpa[i][j].end(); itr++) {
				cur = itr->first;
				res = itr->second;
				dpa[i + 1][j][cur ^ a[i + 1][j]] += res;
				dpa[i][j + 1][cur ^ a[i][j + 1]] += res;
			}
		}
	}

	dpb[0][0][b[0][0]] = 1;
	itr = dpb[0][0].begin();
	rep(i, n - 1) {
		rep(j, n - 1 - i) {
			for (itr = dpb[i][j].begin(); itr != dpb[i][j].end(); itr++) {
				cur = itr->first;
				res = itr->second;
				dpb[i + 1][j][cur ^ b[i + 1][j]] += res;
				dpb[i][j + 1][cur ^ b[i][j + 1]] += res;
			}
		}
	}

	ans = 0;
	rep(i, n) {
		j = n - 1 - i;
		for (itr = dpa[i][j].begin(); itr != dpa[i][j].end(); itr++) {
			cur = (itr->first ^ a[i][j]);
			res = itr->second;
			ans += res * dpb[j][i][cur];
		}
	}
	cout << ans << endl;
}