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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf;
	cin >> n >> m;
	vector<vector<long long>> a(m, vector<long long>(0));
	vector<vector<bool>> b(n, vector<bool>(n, false));
	rep(i, m) {
		cin >> k;
		rep(j, k) {
			cin >> x;
			x--;
			a[i].push_back(x);
		}
		rep(x, a[i].size()) {
			for (y = x + 1; y < a[i].size(); y++) {
				b[a[i][x]][a[i][y]] = b[a[i][y]][a[i][x]] = true;
			}
		}
	}
	
	rep(i, n) {
		for (j = i + 1; j < n; j++) {
			if (!b[i][j]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}