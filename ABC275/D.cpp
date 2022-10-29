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

map<long long, long long> mp;
long long func(long long n) {
	if (mp[n] != 0) {
		return mp[n];
	}
	return mp[n] = func(n / 2) + func(n / 3);
}
int main() {
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	mp[0] = 1;
	cout << func(n) << endl;
}