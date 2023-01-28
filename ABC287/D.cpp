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
	string s, t;
	cin >> s >> t;
	n = s.size(); m = t.size();

	ans = 0;
	rep(j, m) {
		if (s[n - m + j] == t[j] || s[n - m + j] == '?' || t[j] == '?') {
			ans++;
		}
	}
	rep(j, m + 1) {
		//cout << ans;
		if (ans == m) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		if (j == m) {
			break;
		}
		if (s[n - m + j] == t[j] || s[n - m + j] == '?' || t[j] == '?') {
			ans--;
		}
		if (s[j] == t[j] || s[j] == '?' || t[j] == '?') {
			ans++;
		}
	}

}