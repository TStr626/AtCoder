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
	long long n, m, i, j, k, x, y, h, w, ans, cur, res, jud, mod, inf;
	cin >> n;
	vector<long long> a(n);
	vector<vector<long long>> b(2, vector<long long>(0));
	rep(i, n) {
		cin >> a[i];
		b[a[i] % 2].push_back(a[i]);
	}

	ans = -1;
	rep(i, 2) {
		if (b[i].size() >= 2) {
			sort(b[i].begin(), b[i].end());
			m = b[i].size();
			ans = max(ans, b[i][m - 1] + b[i][m - 2]);
		}
	}
	cout << ans << endl;
}