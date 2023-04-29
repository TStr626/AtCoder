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
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) {
		cin >> s[i];
	}
	n = min(h, w);
	vector<long long> vans(n);
	vector<long long> dx = { 1,-1,-1,1,0 }, dy = { 1,1,-1,-1,0 };
	rep(i, h) {
		rep(j, w) {
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
				continue;
			}
			jud = 1;
			rep(k, 5) {
				if (s[i + dx[k]][j + dy[k]] == '.') {
					jud = 0;
				}
			}
			if (jud == 0) {
				continue;
			}
			cur = 0;
			while (true) {
				if (i - cur < 0 || j - cur < 0) {
					break;
				}
				if (s[i - cur][j - cur] == '.') {
					break;
				}
				rep(k, 4) {
					s[i + cur * dx[k]][j + cur * dy[k]] = '.';
				}
				cur++;
			}
			vans[cur-2]++;
		}
	}
	vec_h(vans);
}