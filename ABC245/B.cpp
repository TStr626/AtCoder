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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	set<long long> st;
	rep(i, n) {
		cin >> j;
		st.insert(j);
	}
	ans = 0;
	while (true) {
		if (st.count(ans)==0) {
			cout << ans << endl; return 0;
		}
		else {
			ans++;
		}
	}
}