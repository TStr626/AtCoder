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
	cin >> n >> m;
	vector<long long> a(n + 1), b(m + 1), c(n + m + 1);
	rep(i, n+1) {
		cin >> a[i];
	}
	rep(j, n+m+1) {
		cin >> c[j];
	}

	for (j = m; j >= 0; j--) {
		cur = c[j + n] / a[n];
		b[j] = cur;
		rep(i, n + 1) {
			c[j + i] -= a[i] * cur;
		}
	}
	rep(j, m+1) {
		if (j) cout << ' ';
		cout << b[j];
	}
	cout << endl;
}