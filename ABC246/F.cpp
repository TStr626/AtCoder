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

int popcount(long long b) {
	int ans = 0;
	while (b) {
		if (b & 1) {
			ans++;
		}
		b /= 2;
	}
	return ans;
}

long long powmod(long long n, long long m, long long mod) {
	// mod>0
	long long i, ans, cur, res;
	if (n % mod == 0) {
		return 0;
	}
	ans = 1; cur = n % mod; res = m;
	while (res > 0) {
		if (res % 2 == 1) {
			ans = (ans * cur) % mod;
		}
		cur = (cur * cur) % mod;
		res /= 2;
	}
	return ans;
}


int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod=998244353;
	long long l, b, c, bcur, sgnb, cntc;
	cin >> n >> l;
	vector<string> s(n);
	vector<long long> bin(n);
	set<long long> st;
	rep(i, n) {
		cin >> s[i];
		bcur = 0;
		for (j = 0; j < s[i].size(); j++) {
			c = s[i][j] - 'a';
			bcur += (1ll << c);
		}
		bin[i] = bcur;
		//cout << bin[i] << endl;
	}

	ans = 0;
	rep(b, (1ll << n)) {
		if (b == 0) {
			continue;
		}
		
		bcur = (1ll << 26) - 1;
		rep(i, n) {
			if (b & (1ll << i)) {
				// can make by s[i]
				bcur &= bin[i];
			}
		}
		sgnb = (popcount(b) % 2 ? 1 : -1);
		cntc = popcount(bcur);

		cur = powmod(cntc, l, mod);

		//cout << b << ':' << cntc << cur << endl;

		ans += cur * sgnb;
		ans = (ans + mod) % mod;
	}
	cout << ans << endl;
}