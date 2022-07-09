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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long t, d;
	cin >> n >> m >> x >> t >> d;
	cur = t - (x * d);
	ans = min(x, m) * d + cur;
	cout << ans << endl;
}