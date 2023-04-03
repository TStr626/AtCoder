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
	vector<set<long long>> ain(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
		ain[a[i]].insert(i);
	}
	queue<long long> qu;
	rep(i, n) {
		if (ain[i].size() == 0) {
			qu.push(i);
		}
	}
	while (qu.size()) {
		cur = qu.front();
		qu.pop();
		ain[a[cur]].erase(cur);
		if (ain[a[cur]].size() == 0) {
			qu.push(a[cur]);
		}
	}
	ans = 0;
	rep(i, n) {
		if (ain[i].size()) {
			ans++;
		}
	}
	cout << ans << endl;
}