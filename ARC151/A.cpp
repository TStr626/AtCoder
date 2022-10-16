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
	cin >> n >> s >> t;

	// possible ?
	cur = 0; res = 0;
	rep(i, n) {
		if (s[i] == '1') {
			cur++;
		}
		if (t[i] == '1') {
			res++;
		}
	}
	if (abs(cur - res) % 2 == 1) {
		cout << -1 << endl;
		return 0;
	}

	//create
	string u = "";
	rep(i, n) {
		u += '0';
	}

	for (i = n - 1; i >= 0; i--) {
		if (cur > res && s[i] == '1' && t[i] == '0') {
			u[i] = '1';
			cur--; res++;
		}
		if (cur < res && s[i] == '0' && t[i] == '1') {
			u[i] = '1';
			cur++; res--;
		}
	}


	cout << u << endl;
}