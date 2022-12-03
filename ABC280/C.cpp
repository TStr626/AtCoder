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
	n = s.size();
	rep(i, n) {
		if (s[i] != t[i]) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << n + 1 << endl;
}