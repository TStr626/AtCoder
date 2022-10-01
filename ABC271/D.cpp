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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 1000000000;
	long long s;
	cin >> n >> s;
	vector<long long> a(n), b(n), t(n);

	cur = 0; res = 0;
	rep(i, n) {
		cin >> a[i] >> b[i];
		if (a[i] <= b[i]) {
			t[i] = 0;
		}
		else {
			t[i] = 1;
			swap(a[i], b[i]);
		}
		b[i] -= a[i];
		cur += a[i];
		res += b[i];
	}
	
	if (s < cur || cur + res < s) {
		cout << "No" << endl;
		return 0;
	}

	vector<vector<bool>> dp(n + 1, vector<bool>(res + 1, false));
	dp[0][0] = true;
	rep(i, n) {
		rep(j, res + 1) {
			dp[i + 1][j] = dp[i][j];
		}
		rep(j, res + 1 - b[i]) {
			dp[i + 1][j + b[i]] = dp[i + 1][j + b[i]] || dp[i][j];
		}
	}
	
	s -= cur;
	if (dp[n][s] == false) {
		cout << "No" << endl;
		return 0;
	}

	string anss = "";
	for (i = n - 1; i >= 0; i--) {
		if (dp[i + 1][s] == true && dp[i][s] == false) {
			s -= b[i];
			if (t[i]) {
				anss += 'H';
			}
			else {
				anss += 'T';
			}
			
		}
		else {
			if (t[i]) {
				anss += 'T';
			}
			else {
				anss += 'H';
			}
		}
	}
	reverse(anss.begin(), anss.end());
	cout << "Yes" << endl;
	cout << anss << endl;
}