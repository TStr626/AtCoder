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
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}

	ans = 0; cur = 0;
	for (i = n - 1; i >= 0; i--) {
		cur += a[i];
		if (cur >= 4) {
			ans = i + 1;
			cout << ans << endl;
			return 0;
		}
	}
	cout << 0 << endl;
}