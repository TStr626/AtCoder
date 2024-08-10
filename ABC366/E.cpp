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
	vector<long long> vx(n),vy(n);
	rep(i, n) {
		cin >> vx[i] >> vy[i];
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	// dx[x-2000000] means sum(abs(xi-(x-2000000)))
	vector<long long> dx(4000001), dy(4000001);
	dx[0] = 0;
	rep(i, n) {
		dx[0] += abs(vx[i] + 2000000);
	}
	
	cur = 0;
	for (x = 1; x <= 4000000; x++) {
		dx[x] = dx[x - 1] + (2 * cur - n);
		while (cur < n && vx[cur] == x - 2000000) {
			cur++;
		}
	}
	
	dy[0] = 0;
	rep(i, n) {
		dy[0] += abs(vy[i] + 2000000);
	}
	cur = 0;
	for (y = 1; y <= 4000000; y++) {
		dy[y] = dy[y - 1] + (2 * cur - n);
		while (cur < n && vy[cur] == y - 2000000) {
			cur++;
		}
	}
	sort(dy.begin(), dy.end());

	ans = 0;
	auto itr = dy.begin();
	for (x = 0; x <= 4000000; x++) {
		itr = upper_bound(dy.begin(), dy.end(), m - dx[x]);
		ans += itr - dy.begin();
	}
	cout << ans << endl;
	
}