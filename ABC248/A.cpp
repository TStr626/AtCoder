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
	string s;
	cin >> s;
	vector<bool> is(10, true);
	rep(i, 9) {
		is[s[i] - '0'] = false;
	}
	rep(i, 10) {
		if (is[i]) {
			cout << i << endl; return 0;
		}
	}
}