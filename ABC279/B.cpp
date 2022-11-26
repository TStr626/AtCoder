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
	if (s.size() < t.size()) {
		cout << "No" << endl;
		return 0;
	}
	rep(i, s.size() - t.size() + 1) {
		rep(j, t.size()) {
			if (s[i + j] != t[j]) {
				break;
			}
		}
		if (j == t.size()) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}