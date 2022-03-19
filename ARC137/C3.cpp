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
#define vb vector<bool>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define vvvvb vector<vvvb>
int main() {

	// experiment for n=4; max(Ai)<20;
	// enumerates all "Bob(Second) wins" inputs

	long long n, m, i, j, k, l, h, w, x, y, ans, cur, res, jud, mod;
	long long j1, j2, j3, j4;
	m = 20;
	vvvvb a(m, vvvb(m, vvb(m, vb(m, false))));
	rep(j1, m) {
		for (j2 = j1 + 1; j2 < m;j2++) {
			for (j3 = j2 + 1; j3 < m; j3++) {
				for (j4 =j3 + 1; j4 < m; j4++) {
					jud = 0;
					for (k = j4 - 1; k > j3; k--) {
						if (a[j1][j2][j3][k] == false) {
							jud = 1;
						}
					}
					for (k = j3 - 1; k > j2; k--) {
						if (a[j1][j2][k][j3] == false) {
							jud = 1;
						}
					}
					for (k = j2 - 1; k > j1; k--) {
						if (a[j1][k][j2][j3] == false) {
							jud = 1;
						}
					}
					for (k = j1 - 1; k >= 0; k--) {
						if (a[k][j1][j2][j3] == false) {
							jud = 1;
						}
					}
					if (jud) {
						a[j1][j2][j3][j4] = true;
					}
					else {
						a[j1][j2][j3][j4] = false;
					}
				}
			}
		}
	}
	rep(j4, m) {
		rep(j3, j4) {
			rep(j2, j3) {
				rep(j1, j2) {
					if (a[j1][j2][j3][j4] == false) {
						cout << j1 << ' ' << j2 << ' ' << j3 << ' ' << j4 << endl;
					}
				}
			}
		}
	}
}