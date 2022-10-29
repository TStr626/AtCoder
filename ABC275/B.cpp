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
	long long a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	a %= mod; b %= mod; c %= mod; d %= mod; e %= mod; f %= mod;
	ans = ((((a * b) % mod * c) % mod) - (((d * e) % mod * f) % mod) + mod) % mod;
	cout << ans << endl;
}