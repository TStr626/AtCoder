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

struct pos {
	long long x;
	long long y;
};
bool operator<(pos a, pos b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.y < b.y;
}

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	cin >> w >> h >> n;
	vector<pos> p(n);
	rep(i, n) {
		cin >> p[i].x >> p[i].y;
	}

	long long s, t;
	cin >> s;
	vector<long long> a(s);
	rep(i, s) {
		cin >> a[i];
	}
	
	cin >> t;
	vector<long long> b(t);
	rep(j, t) {
		cin >> b[j];
	}

	map<pos, long long> mp;
	cur = 0; res = (s + 1) * (t + 1);
	rep(i, n) {
		x = lower_bound(a.begin(), a.end(), p[i].x) - a.begin();
		y = lower_bound(b.begin(), b.end(), p[i].y) - b.begin();
		//cout << x << y << endl;
		if (mp[{x,y}] == 0) {
			res--;
		}
		
		cur = max(cur, ++mp[{x, y}]);;
	}
	if (res) {
		ans = 0;
	}
	else {
		ans = n;
		for (auto c : mp) {
			ans = min(c.second, ans);
		}
	}
	cout << ans << ' ' << cur << endl;
}