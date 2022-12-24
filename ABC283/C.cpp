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
	string s;
	cin >> s;
	n = s.size();
	ans = 0;
	i = 0;
	while (i < n) {
		if (i < n - 1 && s[i] == '0' && s[i + 1] == '0') {
			i += 2;
		}
		else {
			i++;
		}
		ans++;
	}
	cout << ans << endl;
}