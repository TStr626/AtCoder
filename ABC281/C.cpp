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
	cin >> n >> x;
	vector<long long> a(n);
	res = 0;
	rep(i, n) {
		cin >> a[i];
		res += a[i];
	}
	
	x %= res;
	rep(i, n) {
		if (x < a[i]) {
			break;
		}
		x -= a[i];
	}
	ans = (i + 1);
	cout << ans << ' ' << x << endl;
}