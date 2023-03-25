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
	string s;
	cin >> s;
	ans = 0;
	vector<long long> b(1024, 0);
	b[0] = 1;
	n = s.size();
	cur = 0;
	rep(i, n) {
		res = s[i] - '0';
		cur ^= (1ll << res);
		ans += b[cur];
		b[cur]++;
	}
	cout << ans << endl;
}