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
	vector<vector<long long>> a(n, vector<long long>(n + 1, 0));
	rep(i, n) {
		a[i][0] = 1;
		for (j = 1; j <= i; j++) {
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}

	rep(i, n) {
		rep(j, i + 1) {
			if (j) cout << ' ';
			cout << a[i][j];
		}
		cout << endl;
	}
}