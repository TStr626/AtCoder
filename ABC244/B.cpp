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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod = 998244353;
	string t;
	cin >> n >> t;
	vector<long long> dx = { 1,0,-1,0 }, dy = { 0,-1,0,1 };
	cur = 0; x = 0; y = 0;
	rep(i, n) {
		if (t[i] == 'S') {
			x += dx[cur];
			y += dy[cur];
		}
		else {
			cur = (cur + 1) % 4;
		}
	}
	cout << x << ' ' << y << endl;
}