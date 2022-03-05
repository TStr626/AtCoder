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
	string s;
	cin >> s;
	long long query, t;
	char c;
	cin >> query;
	while (query--) {
		cin >> t >> k;
		k--;
		cur = 0;
		while (k > 0 && t > 0) {
			if (k % 2) {
				cur++;
			}
			cur++;
			k /= 2;
			t--;
		}
		cur += t;
		cur += (s[k] - 'A');
		cur %= 3;
		c = 'A' + cur;
		cout << c << endl;
	}
}