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
	long long n, m, i, j, k, h, w, x, y, ans, cur, res, jud, mod, inf=1100000000;
	string s;
	cin >> n >> s;
	if (n == 2 && s[0] != s[1]) {
		cout << "No" << endl;
	}
	else if (s[0] == 'A' && s[n - 1] == 'B') {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

}