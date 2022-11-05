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
	for (i = n - 1; i >= 0; i--) {
		if (s[i] == 'a') {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}