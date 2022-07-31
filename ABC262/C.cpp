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
	long long n, m, i, j, k, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<long long> a(n);

	ans = 0; cur = 0;

	rep(i, n) {
		cin >> a[i];
		a[i]--;
		if (i == a[i]) {
			ans += cur;
			cur++;
		}
	}

	rep(i, n) {
		cur = a[i];
		if (cur == i) {
			continue;
		}
		if (cur>i && a[cur] == i) {
			ans++;
		}
	}
	cout << ans << endl;
}