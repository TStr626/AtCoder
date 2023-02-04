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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n >> k;
	vector<long long> a(n);
	vector<vector<long long>> s(k, vector<long long>(n + 1, 0));
	cur = 0;
	rep(i, n) {
		cin >> a[i];
		s[i % k][i + 1] = a[i];
	}

	rep(i, k) {
		rep(j, n) {
			s[i][j + 1] += s[i][j];
		}
	}

	long long query;
	cin >> query;
	while (query--) {
		cin >> x >> y;
		x--;
		jud = 1;
		res = s[0][y] - s[0][x];
		rep(i, k) {
			if (s[i][y] - s[i][x] != res) {
				jud = 0;
			}
		}
		if (jud) {
			yes();
		}
		else {
			no();
		}
	}
}