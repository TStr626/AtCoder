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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf = 100000000;
	long long h2, w2;
	cin >> h >> w >> n >> h2 >> w2;
	vector<vector<long long>> a(h, vector<long long>(w));
	vector<long long> cnt(n, 0);
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
			a[i][j]--; // 0-indexed
			cnt[a[i][j]]++;
		}
	}

	vector<vector<vector<long long>>> s(n, vector<vector<long long>>(h + 1, vector<long long>(w + 1, 0)));
	rep(i, h) {
		rep(j, w) {
			s[a[i][j]][i + 1][j + 1] = 1;
		}
	}

	rep(x, n) {
		rep(i, h + 1) {
			rep(j, w) {
				s[x][i][j + 1] += s[x][i][j];
			}
		}

		rep(j, w + 1) {
			rep(i, h) {
				s[x][i + 1][j] += s[x][i][j];
			}
		}
	}

	rep(i, h - h2 + 1) {
		rep(j, w - w2 + 1) {
			ans = n;
			rep(x, n) {
				cur = s[x][i + h2][j + w2] - s[x][i][j + w2] - s[x][i + h2][j] + s[x][i][j];
				if (cur == cnt[x]) {
					ans--;
				}
			}

			if (j > 0) cout << ' ';
			cout << ans;
		}
		cout << endl;
	}
}