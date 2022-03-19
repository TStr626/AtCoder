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
	// experiment for n=3; max(Ai)<10;
	// enumerates all "Bob(Second) wins" inputs
	long long n, m, i, j, k, l, h, w, x, y, ans, cur, res, jud, mod;
	
	m = 10;
	vector < vector<vector<bool>>> a(m, vector<vector<bool>>(m, vector<bool>(m, false)));
	rep(i, m) {
		for (j = i + 1; j < m; j++) {
			for (k = j + 1; k < m; k++) {
				jud = 0;
				for (l = k - 1; l > j; l--) {
					if (a[i][j][l] == false) {
						jud = 1;
					}
				}
				for (l = j - 1; l > i; l--) {
					if (a[i][l][j] == false) {
						jud = 1;
					}
				}
				for (l = i - 1; l >= 0; l--) {
					if (a[l][i][j] == false) {
						jud = 1;
					}
				}
				if (jud) {
					a[i][j][k] = true;
				}
				else {
					a[i][j][k] = false;
				}
			}
		}
	}
	rep(k, m) {
		rep(j, k) {
			rep(i, j) {
				if (a[i][j][k] == false) {
					cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}

	}
}