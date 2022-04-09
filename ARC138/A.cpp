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

vector<int> compress(vector<int> a, int begin_value) {
	// need <map>,<algorithm>
	int i, n = a.size();
	map<int, int> mp;
	auto b = a;
	sort(b.begin(), b.end());
	int cur, res;
	res = b[0] - 1; cur = begin_value - 1;
	for (i = 0; i < n; i++) {
		if (b[i] > res) {
			res = b[i];
			cur++;
			mp[res] = cur;
		}
	}
	for (i = 0; i < n; i++) {
		b[i] = mp[a[i]];
	}
	return b;
}


int main() {
	int n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf=1100000000;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}

	auto b = compress(a, 0);
	/*
	rep(i, n) {
		cout << b[i] << ' ';
	}
	cout << endl;
	*/
	/*
	cur = b[0];
	rep(i, k) {
		cur = min(b[i], cur);
	}
	res = b[k];
	rep(i, n - k) {
		res = max(b[i + k], res);
	}

	//valid check
	if (cur >= res) {
		cout << -1 << endl;
		return 0;
	}
	*/
	vector<int> p(n + 1, inf);
	rep(i, n - k) {
		p[b[i + k]] = min(p[b[i + k]], i);
	}
	for (i = n - 1; i >= 0; i--) {
		p[i] = min(p[i], p[i + 1]);
	}
	/*
	rep(i, n) {
		cout << p[i]  << ' ';
	}
	cout << endl;
	*/
	ans = inf;
	rep(i, k) {
		ans = min(ans, k - i + p[b[i] + 1]);
	}
	if (ans == inf) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}