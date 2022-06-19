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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<vector<long long>> a(n, vector<long long>(n));

	if (n % 2 == 0) {
		// even
		cur = 1;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				a[(i * 2) % n + ((i * 2) >= n)][j] = cur;
				cur++;
			}
		}

	}
	else {
		cur = 1;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				a[(i * 2) % n][j] = cur;
				cur++;
			}
		}
	}

	rep(i, n) {
		rep(j, n) {
			if (j > 0) cout << ' ';
			cout << a[i][j];
		}
		cout << endl;
	}
}