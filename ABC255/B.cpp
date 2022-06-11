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
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod = 998244353;
	cin >> n >> k;
	vector<bool> a(n, false);
	rep(i, k) {
		cin >> cur;
		cur--;
		a[cur] = true;
	}
	vector<double> x(n), y(n);
	rep(i, n) {
		cin >> x[i] >> y[i];
	}

	double ansd, curd, resd;
	ansd = 0;
	rep(i, n) {
		curd = 1000000;
		rep(j, n) {
			if (a[j]) {
				resd = abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]);
				resd = sqrt(resd);
				curd = min(curd, resd);
			}
		}
		ansd = max(ansd, curd);
	}
	cout << setprecision(10);
	cout << ansd << endl;
}