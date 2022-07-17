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
	cin >> n >> x >> y;
	vector<long long> red(n, 0), blu(n, 0);
	red[n - 1] = 1;
	for (i = n - 1; i >= 1; i--) {
		red[i - 1] += red[i];
		blu[i] += red[i] * x;
		red[i] = 0;

		red[i - 1] += blu[i];
		blu[i - 1] += blu[i] * y;
		blu[i] = 0;
	}
	cout << blu[0] << endl;
}