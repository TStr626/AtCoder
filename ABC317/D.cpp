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
void yes() {
	cout << "Yes" << endl;
}
void no() {
	cout << "No" << endl;
}
void vec_h(vector<long long> a) {
	int n = a.size(), i;
	rep(i, n) {
		if (i) cout << ' ';
		cout << a[i];
	}
	cout << endl;
}
void vec_v(vector<long long> a) {
	for (auto c : a) {
		cout << c << endl;
	}
}

struct dom {
	long long x;
	long long y;
	long long z;
};

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> n;
	vector<dom> vd(n);
	k = 0;
	rep(i, n) {
		cin >> vd[i].x >> vd[i].y >> vd[i].z;
		k += vd[i].z;
	}
	vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 10000000000000000));
	dp[0][0] = 0;
	multiset<long long> ms;
	rep(i, n) {
		ms.clear();

		cur = max(0ll, (vd[i].y - vd[i].x + 1) / 2);
		rep(j, k + 1) {
			// no move
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			
			// move
			ms.insert(dp[i][j]);
			res = *ms.begin();
			dp[i + 1][j] = min(dp[i + 1][j], res + cur);
			if (j >= vd[i].z) {
				ms.erase(ms.find(dp[i][j - vd[i].z]));
			}
		}
	}
	cout << dp[n][(k + 1) / 2] << endl;

	

}