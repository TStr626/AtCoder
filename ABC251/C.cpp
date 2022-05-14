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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353, inf = 10000000;
	cin >> n;
	string s;
	long long t;
	ans = 0;
	cur = -1;
	set<string> st;

	rep(i, n) {
		cin >> s >> t;
		if (st.count(s)) {
			continue;
		}
		st.insert(s);
		if (cur < t) {
			ans = i + 1;
			cur = t;
		}
	}
	cout << ans << endl;
}
