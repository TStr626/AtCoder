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
	cin >> n >> m >> k;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}

	multiset<long long> msa, msb;
	ans = 0;
	rep(i, m) {
		msa.insert(a[i]);
		ans += a[i];
	}
	rep(i, m - k) {
		res = *msa.rbegin();
		ans -= res;
		msa.erase(msa.find(res));
		msb.insert(res);
	}
	cout << ans;

	for (i = m; i < n; i++) {
		msa.insert(a[i]);
		ans += a[i];
		res = *msa.rbegin();
		msa.erase(msa.find(res));
		ans -= res;
		msb.insert(res);

		if (msa.find(a[i - m]) != msa.end()) {
			msa.erase(msa.find(a[i - m]));
			ans -= a[i - m];
			res = *msb.begin();
			msa.insert(res);
			ans += res;
			msb.erase(msb.find(res));
		}
		else {
			msb.erase(msb.find(a[i - m]));
		}

		cout << ' ' << ans;

		
	}
	cout << endl;
}