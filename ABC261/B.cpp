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
	vector<string> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	jud = 1;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i][j] == 'W' && a[j][i] == 'L') {

			}
			else if (a[i][j] == 'L' && a[j][i] == 'W') {

			}
			else if (a[i][j] == 'D' && a[j][i] == 'D') {

			}
			else {
				jud = 0;
			}
		}
	}
	if (jud) {
		cout << "correct" << endl;
	}
	else {
		cout << "incorrect" << endl;
	}
	
}