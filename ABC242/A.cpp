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
	long long a, b, c;
	cin >> a >> b >> c >> x;
	double ansp;
	if (x <= a) {
		ansp = 1;
	}
	else if (x <= b) {
		ansp = double(c) / double(b - a);
	}
	else {
		ansp = 0;
	}
	cout << setprecision(9);
	cout << ansp << endl;
}