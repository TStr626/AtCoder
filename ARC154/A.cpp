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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	string a, b;
	cin >> a >> b;
	rep(i, n) {
		if (a[i] < b[i]) {
			swap(a[i], b[i]);
		}
	}
	cur = 0;
	rep(i, n) {
		cur = (cur * 10 + a[i] - '0') % mod;
	}
	res = 0;
	rep(i, n) {
		res = (res * 10 + b[i] - '0') % mod;
	}
	ans = (cur * res) % mod;
	cout << ans << endl;
}