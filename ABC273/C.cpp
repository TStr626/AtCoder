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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf;
	cin >> n;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	vector<long long> ansv(n, 0);
	ans = 0; cur = a[0]; ansv[0] = 1;
	for (i = 1; i < n; i++) {
		if (cur != a[i]) {
			ans++;
			cur = a[i];
		}
		ansv[ans]++;
	}
	rep(i, n) {
		cout << ansv[i] << endl;
	}
}