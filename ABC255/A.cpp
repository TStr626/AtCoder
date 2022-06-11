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
	long long n, m, i, j, k, h, w, ans, cur, res, jud, mod;
	long long r, c;
	cin >> r >> c;
	r--; c--;
	vector<vector<long long>> a(2, vector<long long>(2));
	rep(i, 2) {
		rep(j, 2) {
			cin >> a[i][j];
		}
	}
	cout << a[r][c] << endl;
}