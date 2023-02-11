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
	cin >> n;
	vector<long long> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	cin >> m;
	set<long long> b;
	rep(j, m) {
		cin >> y;
		b.insert(y);
	}
	cin >> x;
	
	queue<long long> qu;
	vector<bool> dp(x + 1, false);
	qu.push(0);
	dp[0] = true;
	while (qu.size()) {
		cur = qu.front();
		qu.pop();
		for (auto i : a) {
			if (cur + i > x) {
				continue;
			}
			if (b.count(cur + i)) {
				continue;
			}
			if (dp[cur + i]) {
				continue;
			}
			dp[cur + i] = true;
			qu.push(cur + i);
		}
	}
	(dp[x]) ? yes() : no();
}