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

vector<long long> primevector(long long n) {
	// enumerates primes under n in O(nlogn)
	long long i, j;
	vector<bool> p(n + 1, true);
	p[0] = false; p[1] = false;
	for (i = 2; i * i <= n; i++) {
		if (p[i]) {
			for (j = 2; i * j <= n; j++) {
				p[i * j] = false;
			}
		}
	}
	vector<long long> pr(0);
	for (i = 2; i <= n; i++) {
		if (p[i]) {
			pr.push_back(i);
		}
	}

	return pr;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	auto p = primevector(1000001);
	m = p.size();
	ans = 0;
	j = m - 1;
	rep(i, m) {
		cur = n / p[i];
		if (cur <= 7) continue;
		while (p[j] * p[j] * p[j] > cur) {
			j--;
		}
		ans += max(j - i, 0ll);
	}
	cout << ans << endl;
}
