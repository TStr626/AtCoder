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

long long h, w;
vector<vector<long long>> a;
set<long long> st;
long long ans;
void dfs(long long i, long long j) {
	if (i >= h || j >= w) {
		return;
	}
	if (st.count(a[i][j])) {
		return;
	}
	if (i == h - 1 && j == w - 1) {
		ans++;
		return;
	}
	st.insert(a[i][j]);
	dfs(i + 1, j);
	dfs(i, j + 1);
	st.erase(a[i][j]);
}
int main() {
	long long n, m, i, j, k, x, y, cur, res, jud, mod;
	cin >> h >> w;
	a.resize(h, vector<long long>(w));
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
		}
	}
	ans = 0;
	dfs(0, 0);
	cout << ans << endl;
}