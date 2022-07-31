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
	cin >> n >> m;
	vector<vector<bool>> g(n, vector<bool>(n, false));
	rep(i, m) {
		cin >> x >> y;
		x--; y--;
		g[x][y] = true;
		g[y][x] = true;
	}

	ans = 0;
	rep(i, n) {
		for (j = i + 1; j < n; j++) {
			for (k = j + 1; k < n; k++) {
				if (g[i][j] && g[j][k] && g[k][i]) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	
}