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
	cin >> n >> k;
	cur = 1; ans = n;
	rep(i, k) {
		cur *= 10;
		ans = ((ans + cur / 2) / cur) * cur;
	}
	cout << ans << endl;

}