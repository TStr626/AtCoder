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
	long long v, a, b, c;
	cin >> v >> a >> b >> c;
	while (true) {
		if (v < a) {
			cout << "F" << endl; break;
		}
		v -= a;
		if (v < b) {
			cout << "M" << endl; break;
		}
		v -= b;
		if (v < c) {
			cout << "T" << endl; break;
		}
		v -= c;
	}
}