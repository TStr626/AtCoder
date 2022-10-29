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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<long long> hv(n);
	ans = -1; cur = 0;
	rep(i, n) {
		cin >> hv[i];
		if (cur < hv[i]) {
			ans = i; cur = hv[i];
		}
	}
	cout << ans + 1 << endl;
}