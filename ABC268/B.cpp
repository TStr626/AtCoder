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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf;
	string s, t;
	cin >> s >> t;
	if (s.size() > t.size()) {
		cout << "No" << endl;
		return 0;
	}

	rep(i, s.size()) {
		if (s[i] != t[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

}