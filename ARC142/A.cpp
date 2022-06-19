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

long long rev(long long x) {
	long long ans, cur;
	ans = 0; cur = x;
	while (cur > 0) {
		ans = ans * 10 + cur % 10;
		cur /= 10;
	}
	return ans;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf=1100000000;
	cin >> n >> k;
	long long cur1, cur2;
	cur1 = rev(k);
	cur2 = rev(cur1);
	if (k > min(cur1, cur2) || k > n) {
		ans = 0;
		cout << ans << endl;
		return 0;
	}

	ans = 0;
	cur = cur2;
	while (cur <= n) {
		cur *= 10;
		ans++;
	}


	if (cur1 != cur2) {
		cur = cur1;
		while (cur <= n) {
			cur *= 10;
			ans++;
		}
	}

	cout << ans << endl;
}