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
	vector<long long> a(n), d(n), s(n);
	cur = 0;
	rep(i, n) {
		cin >> a[i];
		cur += a[i] * i;
	}
	rep(i, n - 1) {
		d[i + 1] = 1;
	}
	res = 0;
	for (i = n - 1; i >= 0; i--) {
		res += a[i];
		s[i] = res;
	}
	
	// possible?
	long long cntp = -1, cntm = -1;
	rep(i, n) {
		if (s[i] < 0) {
			cntm = i;
		}
		if (s[i] > 0) {
			cntp = i;
		}
	}

	if (cur > 0) {
		if (cntm == -1) {
			if (res == 0) {
				cout << "No" << endl;
				return 0;
			}
			// res>0
			d[0] -= ((cur + res - 1) / res);
			cur -= ((cur + res - 1) / res) * res;
			// cntp!=-1
			d[cntp] += (-cur);
		}
		else {
			d[cntm] += cur;
		}

	}
	else if (cur < 0) {
		if (cntp == -1) {
			if (res == 0) {
				cout << "No" << endl;
				return 0;
			}
			// res<0
			res = -res;
			d[0] -= ((-cur + res - 1) / res);
			cur += ((-cur + res - 1) / res) * res;
			// cntm!=-1
			d[cntm] += (cur);
		}
		else {
			d[cntp] += (-cur);
		}
	}

	cout << "Yes" << endl;
	ans = 0;
	rep(i, n) {
		ans += d[i];
		if (i) cout << ' ';
		cout << ans;
	}
}