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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if (s[0] == s[1] && s[1] == s[2]) {
		cout << -1 << endl;
	}
	else if (s[0] != s[1]) {
		cout << s[0] << endl;
	}
	else {
		cout << s[2] << endl;
	}
}