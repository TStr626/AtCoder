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
	long long n, m, i, j, k, x, y, ans, cur, res, jud, mod;
	cin >> n;
	string s;
	map<string, long long> mp;
	rep(i, n) {
		cin >> s;
		if (mp[s] == 0) {
			cout << s << endl;
			mp[s] = 1;
		}
		else {
			cout << s << '(' << mp[s] << ')' << endl;
			mp[s]++;
		}
	}

}