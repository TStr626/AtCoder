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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf;
	long long query;
	cin >> n >> query;
	vector<vector<long long>> a(n, vector<long long>(0));
	rep(i, n) {
		cin >> x;
		rep(j, x) {
			cin >> y;
			a[i].push_back(y);
		}
	}

	while (query--) {
		cin >> x >> y;
		x--; y--;
		cout << a[x][y] << endl;
	}
}