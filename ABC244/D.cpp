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
	string s, t;
	char c;
	rep(i, 3) {
		cin >> c;
		s.push_back(c);
	}
	rep(i, 3) {
		cin >> c;
		t.push_back(c);
	}
	if (s[0] == t[0] && s[1] == t[1] && s[2] == t[2]) {
		cout << "Yes" << endl;
	}
	else if (s[0] == t[1] && s[1] == t[2] && s[2] == t[0]) {
		cout << "Yes" << endl;
	}
	else if (s[0] == t[2] && s[1] == t[0] && s[2] == t[1]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}