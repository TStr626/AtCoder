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
	long long n, m, i, j, k, h, w, x, y, z, ans, cur, res, jud, mod;
	string s;
	cin >> s;
	vector<string> wd = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
	rep(i, 5) {
		if (wd[i] == s) {
			ans = 5 - i;
		}
	}
	cout << ans << endl;
}