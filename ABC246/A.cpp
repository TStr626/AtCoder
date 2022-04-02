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
	vector<int> x(3), y(3);
	rep(i, 3) {
		cin >> x[i] >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	cout << (x[0] == x[1] ? x[2] : x[0]) << ' ';
	cout << (y[0] == y[1] ? y[2] : y[0]) << endl;
}