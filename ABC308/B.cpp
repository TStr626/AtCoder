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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> m;
	vector<string> c(n), d(m);
	rep(i, n) {
		cin >> c[i];
	}
	rep(j, m) {
		cin >> d[j];
	}
	vector<long long> p(m + 1);
	rep(j, m + 1) {
		cin >> p[j];
	}
	map<string, int> mp;
	rep(j, m) {
		mp[d[j]] = j + 1;
	}
	ans = 0;
	rep(i, n) {
		ans += p[mp[c[i]]];
	}
	cout << ans << endl;
}