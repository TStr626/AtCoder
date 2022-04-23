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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	//cout << s << endl;
	jud = 1;
	n = s.size();
	rep(i, n - 1) {
		if (s[i] == s[i + 1]) {
			jud = 0;
		}
	}
	if (!(s[0] >= 'A' && s[0] <= 'Z')) {
		jud = 0;
	}
	if (!(s[n-1] >= 'a' && s[n-1] <= 'z')) {
		jud = 0;
	}
	if (jud) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}