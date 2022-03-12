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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<long long> a(n), b(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}
	ans = 0; cur = 0;
	rep(i, n) {
		rep(j, n) {
			if (a[i] == b[j]) {
				if (i == j) {
					ans++;
				}
				else {
					cur++;
				}
			}
		}
	}
	cout << ans << endl << cur << endl;
}