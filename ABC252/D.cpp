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
	vector<long long> a(n), cnt(200000, 0);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
		cnt[a[i]]++;
	}
	map<long long, long long> mp;
	ans = n * (n - 1) * (n - 2) / 6;
	rep(i, 200000) {
		cur = cnt[i] * (cnt[i] - 1) / 2;
		cur *= (n - cnt[i]);
		cur += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
		ans -= cur;
	}
	cout << ans << endl;
}
