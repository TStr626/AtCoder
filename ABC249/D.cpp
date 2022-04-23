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
	vector<long long> a(n), p(200001, 0);
	rep(i, n) {
		cin >> a[i];
		p[a[i]]++;
	}
	ans = 0;
	rep(i, n) {
		cur = a[i];
		for (j = 1; j * j <= cur; j++) {
			if (cur % j == 0) {
				if (j * j == cur) {
					ans += p[j] * p[j];
				}
				else {
					ans += 2 * p[j] * p[cur / j];
				}
			}
		}
	}
	cout << ans << endl;
}