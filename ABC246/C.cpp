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
	cin >> n >> k >> x;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
		cur = min(k, a[i] / x);
		a[i] -= x * cur;
		k -= cur;
	}
	ans = 0;
	sort(a.begin(), a.end(), greater<long long>());
	rep(i, n) {
		if (k && a[i]) {
			a[i] = 0;
			k--;
		}
		else {
			ans += a[i];
		}
	}
	cout << ans << endl;
}