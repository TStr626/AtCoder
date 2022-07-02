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
	long long query, t;
	string s;
	cin >> n >> query;
	cin >> s;
	cur = 0;
	while(query--) {
		cin >> t >> x;
		if (t == 1) {
			cur = (cur - x + n) % n;
		}
		else {
			cout << s[(cur + x - 1) % n] << endl;
		}
	}
}