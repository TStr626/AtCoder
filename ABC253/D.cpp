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

long long gcd(long long a, long long b) {
	// a,b>0
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}

long long lcm(long long a, long long b) {
	//a*b<=1e18
	//need "gcd"
	return (a / gcd(a, b)) * b;
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long a, b;
	cin >> n >> a >> b;
	ans = n * (n + 1) / 2;

	cur = n / a;
	res = ((cur * (cur + 1)) / 2) * a;
	ans -= res;

	cur = n / b;
	res = ((cur * (cur + 1)) / 2) * b;
	ans -= res;

	x = lcm(a, b);
	cur = n / x;
	res = ((cur * (cur + 1)) / 2) * x;
	ans += res;

	cout << ans << endl;
}
