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
	cin >> w;

	n = 99;
	vector<long long> ansv(3 * n + 1);
	rep(i, n) {
		ansv[i] = i + 1;
	}
	rep(i, n) {
		ansv[i + n] = (i + 1) * 100;
	}
	rep(i, n) {
		ansv[i + 2 * n] = (i + 1) * 10000;
	}
	ansv[3 * n] = 1000000;

	cout << ansv.size() << endl;
	rep(i, 3 * n + 1) {
		if (i) cout << ' ';
		cout << ansv[i];
	}
	cout << endl;
}
