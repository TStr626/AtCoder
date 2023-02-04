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
	cin >> n >> k;
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}
	sort(s.begin(), s.begin() + k);
	rep(i, k) {
		cout << s[i] << endl;
	}
}