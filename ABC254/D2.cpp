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

// experiment

bool isSquare(long long n) {
	long long i;
	for (i = 1; i * i <= n; i++) {
		if (i * i == n) {
			return true;
		}
	}
	return false;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	long long ok, ng, mid;
	vector<long long> a(n + 1);
	rep(i, n + 1) {
		a[i] = i * i;
	}
	ans = 0;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (isSquare(i * j)) {
				cout << i << ' ' << j << endl;
				ans++;
			}
		}
	}
	cout << ans << endl;
	/*
	ans = 0;
	for (i = 1; i <= n; i++) {
		ok = 1; ng = n + 1;
		while (ng - ok > 1) {
			mid = (ng + ok) / 2;
			if (i * a[mid] <= n) {
				ok = mid;
			}
			else {
				ng = mid;
			}
		}
		ans += ok;
		//cout << ok << endl;
	}
	*/
	/*
	for (i = 1; i <= n; i++) {
		ans += n / a[i];
	}
	ans = ans * 2 - n;
	cout << ans << endl;
	*/
}
