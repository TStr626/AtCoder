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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long query;
	cin >> n >> k >> query;
	vector<long long> a(n, 0);
	
	multiset<long long> ms1,ms2;
	ans = 0;
	rep(i, k) {
		ms1.insert(0);
	}
	rep(i, n - k) {
		ms2.insert(0);
	}
	
	auto itr = ms1.begin();
	while (query--) {
		cin >> x >> y;
		x--;
		itr = ms1.find(a[x]);
		if (itr != ms1.end()) {
			ms1.erase(itr);
			ans -= a[x];
			a[x] = y;
			ms1.insert(y);
			ans += y;
		}
		else {
			itr = ms2.find(a[x]);
			ms2.erase(itr);
			a[x] = y;
			ms2.insert(y);
		}
		// swap check
		if (n == k) {
			cout << ans << endl;
			continue;
		}

		itr = ms2.end();
		itr--;
		cur = *ms1.begin();
		res = *itr;
		if (cur < res) {
			ans -= cur;
			ms1.erase(ms1.begin());
			ms2.erase(itr);
			ans += res;
			ms1.insert(res);
			ms2.insert(cur);
		}
		cout << ans << endl;
	}
}