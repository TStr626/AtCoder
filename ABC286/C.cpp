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
	long long a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;

	s += s;
	ans = 1000000000000000;
	rep(i, n) {
		cur = a * i;
		rep(j, n / 2) {
			if (s[i + j] != s[i + n - 1 - j]) {
				cur += b;
			}
		}
		ans = min(cur, ans);
	}
	cout << ans << endl;
}