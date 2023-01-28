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
	vector<string> s(n), t(m);
	rep(i, n) {
		cin >> s[i];
	}
	rep(j, m) {
		cin >> t[j];
	}
	ans = 0;
	rep(i, n) {
		rep(j, m) {
			if (s[i].substr(3, 3) == t[j]) {
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
}