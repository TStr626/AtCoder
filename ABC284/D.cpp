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

void solve() {
	long long n, i, j, p, q;
	cin >> n;
	for (i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			if ((n / i) % i == 0) {
				cout << i << ' ' << n / (i * i) << endl;
				return;
			}
			j = floor(sqrt(n / i + 1));
			cout << j << ' ' << i << endl;
			return;
		}
	}
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
}