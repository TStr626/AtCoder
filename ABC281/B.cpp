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
	jud = 1;
	if (s.size() != 8) {
		jud = 0;
	}
	if (!(isupper(s[0]) && isupper(s[n - 1]))) {
		jud = 0;
	}
	if (!(s[1] >= '1' && s[1] <= '9')) {
		jud = 0;
	}
	rep(i, 5) {
		if (!(s[i + 2] >= '0' && s[i + 2] <= '9')) {
			jud = 0;
		}
	}
	cout << ((jud==1) ? "Yes" : "No") << endl;
}