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

long long dfs(set<long long> ms, long long b) {

	if (ms.size() == 0) {
		return 10000000000;
	}

	long long ans = 0;
	set<long long> cs0, cs1;
	for (auto u : ms) {
		if (u & (1ll << b)) {
			cs1.insert(u);
		}
		else {
			cs0.insert(u);
		}
	}
	if (min(cs0.size(), cs1.size()) > 0) {
		ans += (1ll << b);
	}
	if (b == 0) {
		return ans;
	}
	ans += min(dfs(cs0, b - 1), dfs(cs1, b - 1));
	return ans;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	long long query, c;
	cin >> n;
	set<long long> st;
	rep(i, n) {
		cin >> x;
		st.insert(x);
	}
	ans = dfs(st, 29);
	
	cout << ans << endl;
}