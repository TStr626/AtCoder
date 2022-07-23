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
	vector<long long> a(100, 0);
	cin >> x >> y;
	for (i = x; i < y; i++) {
		a[i]++;
	}
	cin >> x >> y;
	for (i = x; i < y; i++) {
		a[i]++;
	}
	ans = 0;
	for (i = 0; i < 100; i++) {
		if (a[i] == 2) {
			ans++;
		}
	}
	cout << ans << endl;
}