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
	cin >> n;
	string s;
	cin >> s;
	cur = 0;
	rep(i, n) {
		if (s[i] == '"') {
			cur ^= 1;
		}
		if (s[i] == ',' && cur == 0) {
			s[i] = '.';
		}
	}
	cout << s << endl;
}