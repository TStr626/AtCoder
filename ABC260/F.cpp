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

int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	long long s, t;
	cin >> s >> t >> m;

	vector<vector<long long>> st(s, vector<long long>(0));
	vector<vector<long long>> ts(t, vector<long long>(0));
	vector<vector<long long>> tt(t, vector<long long>(t, -1));
	rep(i, m) {
		cin >> x >> y;
		x--; y--; y -= s;

		rep(j, st[x].size()) {
			res = st[x][j];
			if (tt[y][res] == -1) {
				tt[y][res] = x;
				tt[res][y] = x;
			}
			else {
				// answer
				cout << x + 1 << ' ' << s + y + 1 << ' ' << s + res + 1 << ' ' << tt[y][res] + 1 << endl;
				return 0;
			}
		}

		st[x].push_back(y);
		ts[y].push_back(x);
	}

	cout << -1 << endl;

}