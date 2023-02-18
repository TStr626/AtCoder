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

int solve() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	string s;
	cin >> s;
	cur = 0; x = y = -1;
	rep(i, n) {
		if (s[i] == '1') {
			cur++;
			if (cur == 1) {
				x = i;
			}
			if (cur == 2) {
				y = i;
			}
		}
	}
	if (cur % 2) {
		return -1;
	}
	if (n == 3 && s[1] == '1') {
		return -1;
	}
	if (n == 4) {
		if (s == "0110") {
			return 3;
		}
		if (s == "0011" || s == "1100") {
			return 2;
		}
		else {
			return cur / 2;
		}
	}
	if (cur == 2 && abs(x - y) == 1) {
		return 2;
	}
	return cur / 2;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << solve() << endl;
	}
}