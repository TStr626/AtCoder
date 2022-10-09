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
	long long test;
	string s;
	cin >> test;
	long long c0, c1, cn, l, r;
	while (test--) {
		cin >> n >> k >> s;
		
		l = n; r = -1;
		rep(i, n) {
			if (s[i] == '1') {
				l = min(l, i);
				r = max(r, i);
			}
		}

		// possible range?
		if (r - l + 1 > k) {
			cout << "No" << endl;
			continue;
		}

		
		if (l == n) {
			// no '1'
			jud = 0;
			c0 = 0; c1 = 0; cn = 0;
			rep(i, k) {
				if (s[i] == '0') {
					c0++;
				}
			}

			if (c0 == 0) {
				jud++;
			}
			for (i = k; i < n; i++) {
				if (s[i] == '0') {
					c0++;
				}
				if (s[i - k] == '0') {
					c0--;
				}

				if (c0 == 0) {
					jud++;
				}
			}

			if (jud == 1) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		else {
			// at lease one '1'
			jud = 0;
			c0 = 0;
			
			rep(i, k) {
				if (s[i] == '0') {
					c0++;
				}
			}
			if (c0 == 0 && r <= k - 1) {
				jud++;
			}

			for (i = k; i < n; i++) {
				if (s[i] == '0') {
					c0++;
				}
				if (s[i - k] == '0') {
					c0--;
				}

				if (c0 == 0 && i - k + 1 <= l && r <= i) {
					jud++;
				}
			}

			if (jud == 1) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}

		

	}
	

	
}