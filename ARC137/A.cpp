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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long l, r;
	cin >> l >> r;
	cur = 0;
	for (i = 0; i <= cur; i++) {
		for (j = 0; j <= i; j++) {
			cur = l + j;
			res = r - i + j;
			//cout << res << ' ' << cur << endl;
			if (gcd(cur, res) == 1) {
				
				cout << res - cur << endl;
				return 0;
			}
		}
	}

}