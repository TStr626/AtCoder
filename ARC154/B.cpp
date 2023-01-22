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
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<int> cnts(26, 0), cntt(26, 0);
	rep(i, n) {
		cnts[s[i] - 'a']++;
		cntt[t[i] - 'a']++;
	}
	rep(j, 26) {
		if (cnts[j] != cntt[j]) {
			cout << -1 << endl;
			return 0;
		}
	}

	j = n - 1;
	ans = 0;
	for (i = n - 1; i >= 0; i--) {
		while (j >= 0 && s[i] != t[j]) {
			ans++;
			j--;
		}
		if (j >= 0) {
			j--;
		}
	}
	cout << ans << endl;
}
