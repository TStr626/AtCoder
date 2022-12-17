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
	cin >> n >> m;
	string s;
	vector<long long> a(n, 0);
	rep(i, n) {
		cin >> s;
		rep(j, m) {
			if (s[j] == 'o') {
				a[i] |= (1ll << j);
			}
		}
	}

	ans = 0;
	rep(i, n) {
		for (j = i + 1; j < n; j++) {
			if ((a[i] | a[j]) == (1ll << m) - 1) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}