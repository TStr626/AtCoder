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
	cin >> n;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	map<long long, long long> mp; // 1-indexed
	set<long long> st;
	vector<long long> dec(n, -1);
	for (i = n - 1; i >= 0; i--) {
		if (a[i] < i) {
			// impossible
			ans = 0;
			cout << ans << endl;
			return 0;
		}
		if (a[i] == i) {
			// add a tag
			mp[a[i]] = i + 1;
		}
		if (a[i] > i) {
			// only one possible
			if (mp[a[i]] == 0) {
				// impossible
				ans = 0;
				cout << ans << endl;
				return 0;
			}
			dec[i] = (mp[a[i]] - 1);
			if (st.count(dec[i])) {
				// impossible
				ans = 0;
				cout << ans << endl;
				return 0;
			}
			st.insert(dec[i]);
			mp[a[i]] = i + 1;
		}
	}
	/*
	rep(i, n) {
		cout << dec[i] << ' ';
	}
	cout << endl;
	*/
	cur = 0; ans = 1;
	rep(i, n) {
		cur++;
		if (dec[i] != -1) {
			continue;
		}
		while (st.size() && *st.begin() <= i) {
			//cout << *st.begin() << endl;
			st.erase(st.begin());
			cur--;
		}
		if (cur <= 0) {
			// impossible
			ans = 0;
			cout << ans << endl;
			return 0;
		}
		ans = (ans * cur) % mod;
		cur--;
	}
	cout << ans << endl;
}