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
	cin >> n;
	long long a, b;
	a = n / 16; b = n % 16;
	vector<char> hex(16);
	rep(i, 10) {
		hex[i] = '0' + i;
	}
	rep(i, 6) {
		hex[10 + i] = 'A' + i;
	}
	cout << hex[a] << hex[b] << endl;

}