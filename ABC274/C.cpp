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
	vector<long long> a(2 * n + 1), d(2 * n + 1, 0);
	d[0] = 0;
	rep(i, n) {
		cin >> a[i];
		a[i]--;
		d[2 * (i + 1) - 1] = d[a[i]] + 1;
		d[2 * (i + 1)] = d[a[i]] + 1;
	}

	rep(i, 2 * n + 1) {
		cout << d[i] << endl;
	}
	
}