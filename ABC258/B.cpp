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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<vector<long long>> a(n, vector<long long>(n));
	char c;
	rep(i, n) {
		rep(j, n) {
			cin >> c;
			a[i][j] = c - '0';
		}
	}

	vector<long long> dx = { 1,1,1,0,n - 1,n - 1,n - 1,0 }, dy = { 1,0,n - 1,n - 1,n - 1,0,1,1};
	long long dir, curx, cury;
	ans = 0;
	rep(i, n) {
		rep(j, n) {
			rep(dir, 8) {
				cur = 0;
				curx = i; cury = j;
				rep(k, n) {
					cur = cur * 10 + a[curx][cury];
					curx = (curx + dx[dir]) % n;
					cury = (cury + dy[dir]) % n;
				}
				ans = max(ans, cur);
			}
		}
	}
	cout << ans << endl;
}