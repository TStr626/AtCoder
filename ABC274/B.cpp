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
	long long n, m, i, j, k, h, w,  y, ans, cur, res, jud, mod, inf;
	cin >> h >> w;
	vector<string> c(h);
	vector<long long> x(w, 0);

	rep(i, h) {
		cin >> c[i];
	}

	rep(i, h) {
		rep(j, w) {
			if (c[i][j] == '#') {
				x[j]++;
			}
		}
	}
	rep(j, w) {
		if (j)cout << ' ';
		cout << x[j] ;
	}
	cout << endl;
}