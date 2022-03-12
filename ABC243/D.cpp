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

int main() {
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod;
	long long x;
	string s, t;
	cin >> n >> x >> s;
	t = "";
	while (x > 0) {
		if (x % 2) {
			t.push_back('1');
		}
		else {
			t.push_back('0');
		}
		x /= 2;
	}
	reverse(t.begin(), t.end());
	rep(i, n) {
		if (s[i] == 'U') {
			t.pop_back();
		}
		else if (s[i] == 'L') {
			t.push_back('0');
		}
		else {
			t.push_back('1');
		}
	}
	ans = 0; cur = 1;
	while (t != "") {
		if (t[t.size() - 1] == '1') {
			ans += cur;
		}
		else {
			//
		}
		cur *= 2;
		t.pop_back();
	}
	cout << ans << endl;

}