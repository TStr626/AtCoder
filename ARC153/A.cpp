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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod;
	cin >> n;
	vector<int> s(6);
	cur = n - 1;
	rep(i, 6) {
		s[5 - i] = cur % 10;
		cur /= 10;
	}
	s[0]++;
	ans = 0;
	vector<int> d = { 0,0,1,2,3,3,4,5,4 };
	rep(i, 9) {
		ans = ans * 10 + s[d[i]];
	}
	cout << ans << endl;
	
}